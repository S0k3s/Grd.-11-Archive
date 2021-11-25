#include <iostream>
using namespace std;

int main () {
	int a;
	double b = 0;
	double c = 1;
	double d = 0;

	cout << " How many Values would you like: ";
	cin >> a;

	for (int i = 1; i <= a; i++) {

		if (i == 1) {
			cout << b << ", ";
		}
		else if (i == 2) {
			cout << c << ", ";
		}
		else {
			d = (b + c);
			cout << d << ", ";
			b = c;
			c = d;
		}	
	}

return 0;
}