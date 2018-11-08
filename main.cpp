#include <iostream>
#include <stdexcept>

#define NEW_ENUM_VALUE

using namespace std;

enum State {
	Ready,
	Running
#ifdef NEW_ENUM_VALUE
	,Preparation
#endif
};

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
}

