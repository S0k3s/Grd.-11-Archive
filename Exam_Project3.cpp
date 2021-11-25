#include <iostream> 
using namespace std;

int main() {
	int start[2]; // starting coordinate
	int dest[2]; // ending coordinate
	int battery; // total available battery
	int distance; // total distance appart
	char output;

	cin >> start[0] >> start[1];
	cin >> dest[0] >> dest[1];
	cin >> battery;

	if (start[0] > dest[0]) {
		if (start[1] > dest[1])
			distance = (start[0] - dest[0]) + (start[1] - dest[1]);
		else
			distance = (start[0] - dest[0]) + (dest[1] - start[1]);
	}
	else {
		if (start[1] > dest[1])
			distance = (dest[0] - start[0]) + (start[1] - dest[1]);
		else
			distance = (dest[0] - start[0]) + (dest[1] - start[1]);
	}

	if (distance > battery)
		output = "N"
	else if (distance % 2 == 0 && battery % 2 != 0)
		out
	return 0;
}