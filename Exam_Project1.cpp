#include<iostream>
using namespace std;

int main() {
	int a; // First coordinate
	int b; // second coordinate
	int aState; // State of a
	int bState; // State of b
	int position;

	cin >> a;
	cin >> b;

	if (a <= 0)
		aState = 0;
	else 
		aState = 1;

	if (b <= 0)
		bState = 0;
	else 
		bState = 1;
	
	if (aState == 1) {
		if (bState == 1) 
			position = 1;
		else 
			position = 4;
	}

	if (aState == 0) {
		if (bState == 1)
			position = 2;
		else
			position = 3;
	}

	cout << "\n" << position;

	return 0;
}