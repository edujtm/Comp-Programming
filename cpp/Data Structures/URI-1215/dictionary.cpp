#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string entrada;
	set<string> dictionary;

	while (getline(cin, entrada))  {
		int aux = 0, cont = 0;
		for (int i = 0; i< entrada.size(); ) {
			if (entrada[i] >= 'A' && entrada[i] <= 'Z') entrada[i] += 32;
			if (!(entrada[i] >= 'a' && entrada[i] <= 'z') && entrada[i] != ' ') {
				entrada[i] = ' ';
			} else {
				if (entrada[i] == ' ') {
					dictionary.insert(entrada.substr(aux, cont));
					aux = i+1;
					cont = -1;
				}
				cont++;
				++i;
			}
		}
		dictionary.insert(entrada.substr(aux));
	}

	dictionary.erase("");
	for(auto it = dictionary.begin(); it != dictionary.end(); it++) {
		cout << (*it) << endl;
	}
}
