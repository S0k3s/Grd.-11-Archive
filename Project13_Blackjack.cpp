#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

int main() {
	int a;
	int esc;
	int selection;
	int handTotal;
	int dealerTotal;
	vector<int> playerHand;
	vector<int> dealerHand;
	srand(time(NULL));

	cout << "Welcome to blackjack, ";
	system ("pause");
	for (; ; ) {
		for (int i = 1; i <= 2; i++) {
			a = rand() % 13 + 1; // Getting the random number
			if (a > 10)
				a = 10;
			playerHand.push_back(a); // Pushing into player's hand

			a = rand() % 13 + 1; // Getting the random number
			if (a > 10)
				a = 10;
			dealerHand.push_back(a); // Pushing into dealer's hand
		}

		cout << "1. Hit \n" << "2. Stay \n";
		cout << "Your hand: " << playerHand[0] << " " << playerHand[1] << " Dealers Hand: " << dealerHand[0] << " - \n";

		for (; ;) { // Players turn
			cin >> selection;
			handTotal = 0;

			if (selection == 1) {
				a = rand() % 13 + 1; // Getting the random number
				if (a > 10)
					a = 10;
				playerHand.push_back(a); // Pushing into player's hand
				cout << "Your hand: ";

				for (int i = 0; i < playerHand.size(); i++) { // Run the amount of values in the vector
					cout << playerHand[i] << " "; // display the values
				}
				cout << endl;

				for (int i = 0; i < playerHand.size(); i++) { // Run the amount of values in the vector
					handTotal = playerHand[i] + handTotal; // add all the values together
				}

				if (handTotal >= 21) {
					cout << "Your hand Total: " << handTotal << endl << endl;
					break;
				}
			}

			if (selection == 2) {
				handTotal = 0;
				for (int i = 0; i < playerHand.size(); i++) { // Run the amount of values in the vector
					handTotal = playerHand[i] + handTotal; // add all the values together
				}
				cout << "Your hand Total: " << handTotal << endl << endl;
				break;
			}

		}

		for (; ; ) { // Dealers turn
			dealerTotal = 0;
			cout << "Dealers hand: ";

			for (int i = 0; i < dealerHand.size(); i++) { // Run the amount of values in the vector
				dealerTotal = dealerHand[i] + dealerTotal; // add all the values together
				cout << dealerHand[i] << " "; // display the values
			}
			cout << endl;

			if (dealerTotal >= 21) {
				cout << "Dealers hand Total: " << dealerTotal << endl << endl;
				break;
			}

			else if (dealerTotal >= 17) {
				cout << "Dealers hand Total: " << dealerTotal << endl << endl;
				break;
			}

			else {
				a = rand() % 13 + 1; // Getting the random number
				if (a > 10)
					a = 10;
				dealerHand.push_back(a); // Pushing into dealer's hand
			}
		}

		if (handTotal > 21) {
			cout << "You busted!! \n";
		}

		if (dealerTotal > 21) {
			cout << "Dealer bust!! \n";
		}

		if (handTotal == 21) {
			cout << "Blackjack!! \n";
		}

		if (dealerTotal == 21) {
			cout << "Dealer Blackjack!! \n";
		}

		if (handTotal > dealerTotal && handTotal <= 21) {
			cout << "Win!! \n";
		}

		else if (handTotal < dealerTotal && dealerTotal <= 21) {
			cout << "Dealer Wins!! \n";
		}

		else {
			cout << "Dealer wins!! \n";
		}
		cout << endl << endl << "Press 9 to quit or any other button to continue...";
		cin >> esc;
		if (esc == 9)
			return 0;
		cout << endl << endl;
		handTotal = 0;
		dealerTotal = 0;
		playerHand.clear();
		dealerHand.clear();
	}
}