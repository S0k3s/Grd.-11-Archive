#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int a; // Users guess
	int b; // Random number

	for (; ; ) {
		cout << "Guess the number: ";

		srand(time(NULL));
		b = rand() % 1000 + 1;
		cin >> a;

		for (int i = b; i != a;) {
			if (a > b) {
				cout << "Too High!! \n";
			}

			if (a < b) {
				cout << "Too Low!! \n";
			}
			cin >> a;
		}
		cout << "Good Job!!";
	}
}