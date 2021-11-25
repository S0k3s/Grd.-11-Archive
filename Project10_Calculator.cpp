#include <iostream>
using namespace std;

int main() {
	double input01;
	char opperator;
	double input02;
	double output;

	cout << "Enter your calculation bellow, use # for square root and a space for the second input" << endl;
	
	cin >> input01 >> opperator;
	if (opperator != '#')
		cin >> input02;

	switch (opperator)
	{
	case '+': output = input01 + input02; break;
	case '-': output = input01 - input02; break;
	case '*': output = input01 * input02; break;
	case '/': output = input01 / input02; break;
	case '^': output = pow(input01, input02); break;
	case '#': output = sqrt(input01); break;
	}

	cout << output;

	return 0;
}