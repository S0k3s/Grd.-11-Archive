#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

int SingleLine(int turnCounter) {
	int selection2;
	int numSticks;
	int input;
	int a;

	cout << "1. Easy Mode \n2. Hard Mode \n";
	cin >> selection2;
	numSticks = rand() % 20 + 1; // Number of sticks in the line
	numSticks += 10;

	turnCounter = rand() % 2 + 1; // Seeing who goes first

	for (; ; ) {
		for (int i = 1; i <= numSticks; i++) { // displaying the sticks
			cout << "I ";
		}
		cout << endl << endl;

		if (turnCounter == 1) { // players turn
			cout << "Your turn! \n" << "Choose how many you want to take away: \n" << "1   2   3 \n\n";
			cin >> input;
			switch (input) {
			case 1: numSticks -= 1; break;
			case 2: numSticks -= 2; break;
			case 3: numSticks -= 3; break;
			}
			turnCounter += 1;
		}

		if (numSticks <= 0)
			break;

		if (turnCounter == 2 && selection2 == 1) { // easy mode computer turn
			cout << "Computers turn \n";
			input = rand() % 3 + 1;
			if (input > numSticks)
				input = numSticks;
			switch (input) {
			case 1: numSticks -= 1; cout << "Computer took 1 \n"; break;
			case 2: numSticks -= 2; cout << "Computer took 2 \n"; break;
			case 3: numSticks -= 3; cout << "Computer took 3 \n"; break;
			}
			turnCounter -= 1;
		}
		else if (turnCounter == 2 && selection2 == 2) { // hard mode computer turn
			cout << "Computers turn \n";

			a = numSticks;
			for (; ; ) {
				a -= 4;
				if (a == 1) {
					input = 2;
					break;
				}
				if (a == 2) {
					input = 1;
					break;
				}
				if (a == 3) {
					input = 2;
					break;
				}
				if (a == 4) {
					input = 3;
					break;
				}
			}


			switch (input) {
			case 1: numSticks -= 1; cout << "Computer took 1 \n"; break;
			case 2: numSticks -= 2; cout << "Computer took 2 \n"; break;
			case 3: numSticks -= 3; cout << "Computer took 3 \n"; break;
			}
			turnCounter -= 1;
		}

		if (numSticks <= 0)
			return(turnCounter);
	}
}
int MultiLines(int turnCounter) {
	int selection2;
	int x;
	int y;

	cout << "1. Easy Mode \n2. Hard Mode \n";
	cin >> selection2;

	y = rand() % 8 + 4;

	vector<vector<char>> totalSticks; // multidimentional vector

	for (int i = 0; i < y; i++) {
		totalSticks.push_back(vector<char>());
		x = rand() % 10 + 1;
		for (int j = 0; j < x; j++) {
			totalSticks[i].push_back('I');
		}
	}

	for (; ; ) {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cout << totalSticks[i][j] << " ";
			}
			cout << endl;
		}
	}
	return(turnCounter);
}

int main() {
	int selection1;
	int result = 0;
	srand(time(NULL));

	for (; ; ) {
		cout << "Welcome to nim \n" << "1. Single Line \n" << "2. Multiple Lines \n";
		cin >> selection1;

		if (selection1 == 1) {
			result = SingleLine(result);
		}

		if (selection1 == 2) {
			result = MultiLines(result);
		}

		if (result == 2) {
			cout << "You Lose!!";
		}

		if (result == 1) {
			cout << " You Win!!";
		}
		cout << endl << endl;
	}
	return 0;
}