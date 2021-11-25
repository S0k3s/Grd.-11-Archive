#include <iostream>
using namespace std;

int main () {
	int a; // number for base of triangle
	int b;
	int c;

	cout << "Enter number for the base of the triangle: ";
	cin >> a;

	for (int i = 1; i <= a; i++) {
		for (b = 1; b <= i; b++) {
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = a; i >= 1; i--) {
		
		for (b = 1; b <= i; b++) {
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = a; i >= 1; i--) {
		for (b = i; b <= a; b++) {
			cout << " ";
		}

		for (c = 1; c <= i; c++) {
			cout << "* ";
		}
		cout << endl;
	}
	
	return 0;
}