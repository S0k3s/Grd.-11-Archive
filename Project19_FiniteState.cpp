#include <iostream>
#include <time.h>
using namespace std;

int HP = 10;
int turn = 0;

int Forage() {
	int a;

	for (; ; ) {
		cout << "\nYou currently have " << HP << " HP." << "           Turn " << turn << endl << "You are foraging. \n";
		system("pause");
		turn++;
		a = rand() % 10 + 1;

		if (a <= 6) { // found something
			a = rand() % 10 + 1;
			if (a == 1) { // found poison
				cout << "\nYou found poison!!\n";
				return 2;
			}
			else if (a > 1) { // found food
				if (HP < 10) { // making sure the HP doesnt go over 10
					HP++;
				}
				cout << "\nYou found food.\n";
				return 3;
			}
		}
		HP--;
		cout << "\nYou didn't find anything.\n";
		if (HP == 0) {
			cout << "You are hungry";
			return 2;
		}
	}
}
int Critical() {
	int a;
	HP = 0;

	cout << "\nYou currently have " << HP << " HP." << "           Turn " << turn << endl << "You are in critical condition. \n";
	system("pause");
	turn++;
	a = rand() % 10 + 1;

	if (a <= 3) {
		HP = 10;
		cout << "\nYou have recovered!!" << "           Turn " << turn << endl;
		return 1;
	}
	return 5;
}
int Wandering() {
	int a;

	for (; ; ) {
		cout << "\nYou currently have " << HP << " HP." << "           Turn " << turn << endl << "You are wandering. \n";
		system("pause");
		turn++;
		a = rand() % 100 + 1;

		if (a <= 45) {
			cout << "\nYou found home!\n";
			turn++;
			return 4;
		}
		HP--;
		cout << "\nYou didn't find anything.\n";
		if (a == 0) {
			cout << "You are homesick!!\n";
			return 2;
		}
	}
}
int Home() {
	int a;

	for ( ; ; ) {
	cout << "\nYou are at home. \n" << "You have " << HP << " HP." << "           Turn " << turn << endl << "You are thirsty. \n";
	system("pause");
	turn++;
	a = rand() % 10 + 1;

		if (a <= 4) { // found something
			a = rand() % 10 + 1;
			if (a == 1) { // found poison
				cout << "\nYou found poison!!\n";
				return 2;
			}
			else if (a > 1) { // found water
				if (HP < 9) { // making sure the HP doesnt go over 10
					HP++;
					HP++;
				}
				else if (HP == 9 && HP < 10) {
					HP++;
				}
				cout << "\nYou found water.\n";
				return 1;
			}
		}
		HP--;
		cout << "\nYou found nothing.\n";
		if (HP == 0) {
			cout << "You are dehydrated. \n";
			return 2;
		}
	}
} 

int main() {
	int state = 1;
	srand(time(NULL));

	cout << "Welcome to the finite state machine. \n" << "You will be following an ant as it goes through randomly decided events. \n\n";
	system("pause");

	for (; ; ) {
		if (state == 1) {
			state = Forage();
		}
		if (state == 2) {
			state = Critical();
		}
		if (state == 3) {
			state = Wandering();
		}
		if (state == 4) {
			state = Home();
		}
		else if (state == 5) {
			break;
		}
	}
	cout << "\nThe ant died!! \n" << "You ended at " << turn << " Turns";
	return 0;
}