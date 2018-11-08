#include <iostream>
#include <stdexcept>

using namespace std;

enum State {
	Ready,
	Running
};

int main() {
	State s(State::Ready);

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

