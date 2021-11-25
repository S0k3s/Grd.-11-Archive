#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence; // Entered sentence
	string vowels = "aeiou";
	int numberOfVowels = 0;
	int numberOfConsonants = 0;

	cout << "Enter a sentence here: ";
	getline (cin, sentence);

	for (int i = 0; i < sentence.size(); i++) {

		for (int j = 0; j < 5; j++) {

			if (sentence[i] == ' ') {
				break;
			}
			else if (sentence[i] == vowels[j]) {
				numberOfVowels++;
				break;
			}
			else if (j == 4){
				numberOfConsonants++;
				break;
			}
		}
	}

	cout << "vowels: " << numberOfVowels << endl;
	cout << "consonants: " << numberOfConsonants;

	return 0;
}