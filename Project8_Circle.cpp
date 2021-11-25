#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a;
	double input;
	double areaOutput;
	double radiusOutput;
	double diameterOutput;

	cout << "Press 1 to enter Area, 2 for radius, and 3 for Diameter: ";
	cin >> a;
	cout << "What would you like your value to be? ";
	cin >> input;
	cout << endl;

	if (a == 1) {
		radiusOutput = sqrt(input / M_PI);
		diameterOutput = radiusOutput * 2;
		areaOutput = input;
	}
	else if (a == 2) {
		areaOutput = M_PI * pow(input, 2);
		diameterOutput = input * 2;
		radiusOutput = input;
	}
	else if (a == 3) {
		areaOutput = M_PI * pow((input / 2), 2);
		radiusOutput = input / 2;
		diameterOutput = input;
	}
	else {
		
	}

	cout << "Area = " << areaOutput << endl;
	cout << "Radius = " << radiusOutput << endl;
	cout << "Diameter = " << diameterOutput << endl;

	return 0;
}