#include <iostream>
using namespace std;

int main() {
	double input;
	double guess;

	cout << "Enter a number to find the square root: ";
	cin >> input;
	cout << endl;
	guess = input / 4 + 1;

	for (int i = 1; i <= 5; i++) {
		guess = 0.5 * (guess + input / guess);
		if (input == guess * guess) {
			break;
		}
	}

	cout << "The square root is approximately: " << guess;

	return 0;
}