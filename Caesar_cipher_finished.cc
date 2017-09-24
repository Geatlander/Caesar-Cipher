#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstring>
#include <cctype>
//#include <iterator>




using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::tolower;
using std::toupper;


string& cipher(string &text, const char (&alphabet)[26]) {

	const int secret_key = 12;
	for(char &x : text) {
		
		int alphaindex = 0;
		//cout << "setting alphaindex to zero" << endl;
		
		for(char y : alphabet) {

			char tmpChar = alphabet[alphaindex];
			

			if (toupper(x) == tmpChar) {
				cout << "MATCH:: X= " << x << ", tmpchar = " << tmpChar << endl;

				if((alphaindex) + secret_key > 25) {
					alphaindex = ((alphaindex)+secret_key)-26;
					//cout << "setting alphaindex to zero" << endl;
					x = alphabet[(alphaindex)];
					break;


				}
				else {
					cout << "alphabet index to change to : " << (alphaindex + secret_key) << endl;
					x = alphabet[(alphaindex) + secret_key];
					cout << "X SET TO : " << x << endl;
					break;
				}
			}
			alphaindex++;
			cout << "Can you see this increment?" << endl;
		}
	}
	return text;

}

string decode(string text, const char (&alphabet)[26], int shift_guess) {

	int alphaindex;
	

		for(char &x : text) {
			alphaindex = 25;

			for(char y : alphabet) {
				if (x == alphabet[alphaindex]){
					if((alphaindex) - shift_guess >= 0){
						x = alphabet[alphaindex - shift_guess];
						break;
					}
					else {
						alphaindex = ((alphaindex)- shift_guess)+26;	
						x = alphabet[(alphaindex)];
						break;
					}
				}
				alphaindex--;

			}
		}
	
	return text;

}






int main() {
	const char the_alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	string input;
	string decoded_string;

	cout << "Enter a string to be 'encrypted'" << endl;
	cin >> input;

	string newstring = cipher(input, the_alphabet);
	cout << "New string is: " << newstring << endl;

	cout << "\n\n" << "------------------------------------------------------------------------" << endl;
	cout << "Possibilities of Decoded String::: " << endl;
	for(int x = 1; x < 27; x++) {
		decoded_string = decode(newstring,the_alphabet,x);
		cout << "Shift_guess: " << x << " " << decoded_string << endl;
	}
	decoded_string = decode(newstring, the_alphabet, 12);
	cout << decoded_string<< endl;

}