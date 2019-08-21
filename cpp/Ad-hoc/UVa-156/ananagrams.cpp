#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;


int main() {
	string entrada;
	while (getline(cin, entrada) && entrada[0] != '#') {
		istringstream iss(entrada);
		string word;
		map<string, bool> isAnagram;	
		map<string, set<string>> dict;
		while (iss >> word) {
			for (int i = 0; i < word.size(); ++i) {
				if (word[i] >= 'A' && word[i] <= 'Z') word[i] += 32;
			}
			for (int i = 0; i < word.size(); ++i) {
				map[word].insert(word[i]);
			}
		}		
		for (auto it = dict.begin(); it != dict.end(); ++it) {
 			string & word = it->first;
			if (isAnagram(word) == false) {
			}
		}

	}
}
