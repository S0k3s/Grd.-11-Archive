#include <iostream>
using namespace std;

int main() {
	int a; // First currency selection
	double b; // Amount of money
	int c; // Second currency selection

	cout << "Press key for select currency:" << endl;
	cout << "CAD 1\n" << "USD 2\n" << "GBP 3\n" << "BTC 4\n" << "VND 5\n";
	cin >> a;
	cout << "Enter amount of money to convert: ";
	cin >> b;

	switch (a) {
	case 1: b*= 1; break; // CAD
	case 2: b *= 1.32; break; // USD
	case 3:	b *= 1.70; break; // GBP
	case 4: b *= 14298.55; break; // BTC
	case 5:	b *= 0.000057; break; // VND
	} 

	cout << "Press key for currency to convert to" << endl;
	cout << "CAD 1\n" << "USD 2\n" << "GBP 3\n" << "BTC 4\n" << "VND 5\n";
	cin >> c;

	switch (c) {
	case 1: b *= 1; break; // CAD
	case 2: b *= .76; break; // USD
	case 3:	b *= .59; break;  // GBP
	case 4: b *= 0.000070; break; // BTC
	case 5:	b *= 17596.61; break; // VND
	}

	cout << "Converted amount: " <<"$" << b;

	return 0;
}