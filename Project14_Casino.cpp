#include <iostream>
#include <time.h>
#include <vector>
#include <string>
using namespace std;

int Blackjack(int tokens) {
	int a;
	int bet;
	int esc;
	int push = 0;
	int pushAmount = 0;
	int selection;
	int handTotal;
	int dealerTotal;
	vector<int> playerHand;
	vector<int> dealerHand;
	srand(time(NULL));

	cout << "Welcome to blackjack, ";

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

		cout << "You have " << tokens << " tokens \n";
		cout << "How many tokens would you like to bet? \n";
		cin >> bet;

		if (push == 1) {
			cout << pushAmount << "tokens have been pushed, ";
			bet = pushAmount + bet;
			cout << bet << "are bet. \n";
			push = 0;
			pushAmount = 0;
		}

		cout << endl << "1. Hit \n" << "2. Stay \n";
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
			cout << "You Win!! \n";
			tokens = tokens + bet;
		}

		else if (handTotal < dealerTotal && dealerTotal <= 21) {
			cout << "Dealer Wins!! \n";
			tokens = tokens - bet;
		}

		else if (handTotal > 21 && dealerTotal > 21) {
			cout << "Dealer Wins!! \n";
			tokens = tokens - bet;
		}

		else if (handTotal > 21 && dealerTotal <= 21) {
			cout << "Dealer Wins!! \n";
			tokens = tokens - bet;
		}

		else if (handTotal <= 21 && dealerTotal > 21) {
			cout << "You Win!! \n";
			tokens = tokens + bet;
		}

		else if (handTotal == dealerTotal) {
			cout << "Push!! \n";
			push = 1;
			tokens = tokens - bet;
			pushAmount = bet;
		}

		else {
			cout << "Dealer Wins!!";
			tokens = tokens - bet;
		}

		if (tokens <= 0) {
			return (tokens);
		}

		if (push == 0) {
			cout << endl << endl << "You have " << tokens << " tokens \n" << "Press 9 to cash out and return to the casino floor. \nOr press any other number to play again...";
			cin >> esc;
			if (esc == 9) {
				cout << endl;
				return (tokens);
			}
		}
		cout << endl << endl;
		handTotal = 0;
		dealerTotal = 0;
		playerHand.clear();
		dealerHand.clear();
	}

}
int Mastermind(int tokens) {
	int computersCode[4];
	int num[4];
	int a; // Random number to go into the code
	int esc;
	int bet;
	int redPegs;
	int whitePegs;
	srand(time(NULL));

	for (; ; ) {
		for (int i = 0; i <= 3; i++) {
			a = rand() % 6 + 1; // Getting the random number
			computersCode[i] = a; // Putting the current random number in the array
		}

		// cout << computersCode[0] << computersCode[1] << computersCode[2] << computersCode[3];
		cout << "You have " << tokens << " " << "tokens, " << "How many tokens would you like to bet? \n";
		cin >> bet;
		cout << "The computer guessed a four digit code using numbers 1 - 6 \n" << "Try to guess the code: \n" << endl;

		for (int i = 1; i <= 8; i++) {
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
				}
			}

			for (int i = 0; i <= 3; i++) {
				for (int j = 0; j <= 3; j++) { // Checking correct number
					if (num[i] == computersCode[j] && numState[i] == 0 && comState[j] == 0) {
						whitePegs++;
						numState[i] = 1;
						comState[j] = 1;
					}
				}
			}


			if (redPegs == 4) {
				cout << "\nYou Win!!";
				tokens = tokens + bet;
				break;
			}
			else if (i == 12) {
				cout << "\nYou Lose!!";
				tokens = tokens - bet;
				break;
			}
			cout << "You have " << redPegs << " red peg(s) and " << whitePegs << " white peg(s) \n";
		}
		cout << endl << endl << "You have " << tokens << " tokens \n" << "Press 9 to cash out and return to the casino floor. \nOr press any other number to play again...";
		cin >> esc;
		if (esc == 9) {
			cout << endl;
			return (tokens);
		}
		if (tokens <= 0) {
			cout << endl;
			return (tokens);
		}
	}
}
int RockPaperScissors(int tokens) {
	int computerSelection;
	int playerSelection;
	int result = 1;
	int esc;
	int bet;
	string computerArray[5] = { "Scissors","Paper","Rock","Lizard","Spock" };
	string playerArray[5] = { "Scissors","Paper","Rock","Lizard","Spock" };

	cout << "Rock smashes Scissors \n" << "Paper covers Rock \n" << "Scissors cuts Paper \n" << "Lizard eats Paper \n" << "Paper disproves Spock \n"
		<< "Spock vaporises Rock \n" << "Rock crushes Lizard \n" << "Scissors decapitates Lizard \n" << "Lizard poisons Spock \n" << "Spock smashes Scissors \n"
		<< endl << endl;

	for (; ;) {
		if (result != 0) {
			cout << "You have " << tokens << " " << "tokens, " << "How many tokens would you like to bet? \n";
			cin >> bet;
		}

		srand(time(NULL));
		computerSelection = rand() % 5 + 1;

		cout << "1. Scissors \n" << "2. Paper \n" << "3. Rock \n" << "4. Lizard \n" << "5. Spock \n";
		cout << "Chose Your Weapon: ";
		cin >> playerSelection;
		cout << endl;

		cout << "You threw out " << playerArray[playerSelection - 1] << "! \n";
		cout << "The computer threw out " << computerArray[computerSelection - 1] << "! \n";

		result = playerSelection - computerSelection;
		if (result == 0) {
			cout << "It's a DRAW!! \n";
		}
		else if (result == 4 || result == 2 || result == -1 || result == -3) {
			cout << "You win! \n";
			tokens = tokens + bet;
		}
		else {
			cout << "Get rekt \n";
			tokens = tokens - bet;
		}
		cout << endl;
		if (result != 0) {
			cout << endl << endl << "You have " << tokens << " tokens \n" << "Press 9 to cash out and return to the casino floor. \nOr press any other number to play again...";
			cin >> esc;
			if (esc == 9) {
				cout << endl;
				return (tokens);
			}
			if (tokens <= 0) {
				cout << endl;
				return (tokens);
			}
		}
	}
	return 0;
}
int Number(int tokens) {
	int a; // Users guess
	int b; // Random number
	int bet;
	int esc;
	int rounds = 0;

	for (; ; ) {
		cout << "You have " << tokens << " " << "tokens, " << "How many tokens would you like to bet? \n";
		cin >> bet;

		cout << "Guess the number: ";

		srand(time(NULL));
		b = rand() % 1000 + 1;
		cin >> a;

		for (int i = 1; i <= 9; i++) {
			if (a > b) {
				cout << "Too High!! \n";
			}

			if (a < b) {
				cout << "Too Low!! \n";
			}

			if (a == b) {
				cout << "Good Job!!\n";
				tokens = tokens + bet;
				break;
			}
			cin >> a;
		}

		if (a != b) {
			cout << "You Lose!!\n";
			tokens = tokens - bet;
		}

		cout << endl << endl << "You have " << tokens << " tokens \n" << "Press 9 to cash out and return to the casino floor. \nOr press any other number to play again...";
		cin >> esc;
		if (esc == 9) {
			cout << endl;
			return (tokens);
		}
		if (tokens <= 0) {
			cout << endl;
			return (tokens);
		}
	}
}

int main() {
	int balance = 2000;
	int selection;
	int tokensIn;
	int tokensOut = 0;

	for (; ; ) {
		selection = 0;
		balance = balance + tokensOut;
		cout << "Your current balance is: " << balance << " " << "tokens" << endl << "Your Back on the casino floor. What would you like to play... \n";
		cout << "1. Blackjack \n" << "2. Mastermind \n" << "3. Rock Paper Scissors \n" << "4. Number Guesser \n";
		cin >> selection;
		cout << endl << "How many tokens would you like to bring in? \n";
		cin >> tokensIn;
		balance = balance - tokensIn;
		cout << endl;

		if (selection == 1) {
			tokensOut = Blackjack(tokensIn);
		}
		if (selection == 2) {
			tokensOut = Mastermind(tokensIn);
		}
		if (selection == 3) {
			tokensOut = RockPaperScissors(tokensIn);
		}
		if (selection == 4) {
			tokensOut = Number(tokensIn);
		}
	}
	return 0;
}