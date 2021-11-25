#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int computersCode[4];
	int num[4];
	int a; // Random number to go into the code
	int redPegs;
	int whitePegs;
	srand(time(NULL));

		for (int i = 0; i <= 3; i++) {
			a = rand() % 6 + 1; // Getting the random number
			computersCode[i] = a; // Putting the current random number in the array
		}

		// cout << computersCode[0] << computersCode[1] << computersCode[2] << computersCode[3];
		cout << "The computer guessed a four digit code using numbers 1 - 6 \n" << "Try to guess the code: \n" << endl;

	for (int i = 1; i <= 12; i++) {
		redPegs = 0;
		whitePegs = 0;
		int numState[4]{ 0,0,0,0 };
		int comState[4]{ 0,0,0,0 };
		cin >> num[0] >> num[1] >> num[2] >> num[3];

		for (int i = 0; i <= 3; i++) { // Checking correct spot
			if (computersCode[i] == num[i]) {
				redPegs++;
				numState[i] = 2;
				comState[i] = 2;
				continue;
			}

			for (int j = 0; j <= 3; j++) { // Checking correct number
				if (num[i] == computersCode[j] && numState[i] == 0 && comState[j] == 0) {
					whitePegs++;
					numState[i] = 1;
					comState[j] = 1;
					break;
				}
			}
		}

		if (redPegs == 4) {
			cout << "\nYou Win!!";
			break;
		}
		else if (i == 12) {
			cout << "\nYou Lose!!";
			break;
		}

		cout << "You have " << redPegs << " red peg(s) and " << whitePegs << " white peg(s) \n";
	}
	return 0;
}