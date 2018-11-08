#include <iostream>
#include "overloaded.h"
#include <stdexcept>
#include <variant>

//#define NEW_ENUM_VALUE

using namespace std;

enum State {
	Ready,
	Running
#ifdef NEW_ENUM_VALUE
	,Preparation
#endif
};

namespace State_ {
	class Ready {};
	class Running {};
#ifdef NEW_ENUM_VALUE
	class Preparation {};
#endif

#ifdef NEW_ENUM_VALUE
	using Value = std::variant<State_::Ready, State_::Running, State_::Preparation>;
#else
	using Value = std::variant<State_::Ready, State_::Running>;
#endif
}

int main() {
#ifdef NEW_ENUM_VALUE
	State s(State::Preparation);
#else
	State s(State::Ready);
#endif

	switch (s) {
		case State::Ready:
			cout << "Is ready" << endl;
			break;
		case State::Running:
			cout << "Is running" << endl;
			break;
		default:
			throw logic_error("Unhandled value of enum.");
	}






	State_::Value s2 = State_::Ready();
	std::visit(overloaded {
	             [](State_::Ready arg) {
	               cout << "Is ready c++ 17." << endl;
	             },
	             [](State_::Running arg) {
	               cout << "Is running c++ 17." << endl;
	             },
	           }, s2);

	cout << "Size of enum: " << sizeof (s) << endl;
	cout << "Size of variant: " << sizeof (s2) << endl;
}

