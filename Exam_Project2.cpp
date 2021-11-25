#include <iostream>
#include <vector>
using namespace std;

int main() {
	double N;
	int K;
	double sum = 0;

	cin >> N;
	cin >> K;

	for (int i = 0; i <= K; i++) {
		sum += N;
		N *= 10;
	}

	cout << sum;
	return 0;
}