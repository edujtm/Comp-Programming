#include <cstdio>
#include <iostream>
#include <string>

#define MAXC 110

using namespace std;

int main() {
	
	int n;
	string theString;
	while (cin >> n && n != 0) {
		cin >> theString;
		int g = theString.length()/n;
		for (int i = 0; i<theString.length(); i += g) {
			int j = i;
			int k = i + g - 1;

			while (j < k) {
				char temp = theString[j];
				theString[j] = theString[k];
				theString[k] = temp; 
				++j;
				--k;
			}
		}
		cout << theString << endl;
		cin.ignore();
	}	
}
