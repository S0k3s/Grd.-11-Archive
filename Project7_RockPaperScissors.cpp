#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int main() {
	int computerSelection;
	int playerSelection;
	int result;
	int a;
	string computerArray[5] = {"Scissors","Paper","Rock","Lizard","Spock"};
	string playerArray[5] = {"Scissors","Paper","Rock","Lizard","Spock"};

	cout << "Rock smashes Scissors \n" << "Paper covers Rock \n" << "Scissors cuts Paper \n" << "Lizard eats Paper \n" << "Paper disproves Spock \n"
	<< "Spock vaporises Rock \n" << "Rock crushes Lizard \n" << "Scissors decapitates Lizard \n" << "Lizard poisons Spock \n" << "Spock smashes Scissors \n"
	<< endl << endl;

	for (; ;) {
		
		srand(time(NULL));
		computerSelection = rand() % 5 + 1;

		cout << "1. Scissors \n" << "2. Paper \n" << "3. Rock \n" << "4. Lizard \n" << "5. Spock \n";
		cout << "Chose Your Weapon: ";
		cin >> playerSelection;
		cout << endl;

		cout << "You threw out " << playerArray[playerSelection - 1] << "! \n";
		cout << "The computer threw out " << computerArray[computerSelection - 1] << "! \n";

		result = playerSelection - computerSelection;
		cout << result; 
		if (result == 0) {
			cout << "It's a DRAW!! \n";
		}
		else if (result == 4 || result == 2 || result == -1 || result == -3) {
			cout << "You win! \n";
		}
		else {
			cout << "Get rekt \n";
		}
		cout << endl << endl;
	}
		return 0;
}