#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {

	int inst;
	scanf("%d", &inst);
	for (int i = 0; i < inst; ++i) {
		int n, m;
		char ignore;
		scanf("%d %d%c", &n, &m, &ignore);
		map<string, string> dictionary;
		for (int i = 0; i<n; ++i) {
			string jap, port;
			getline(cin, jap);
			getline(cin, port);
			dictionary[jap] = port;
		}
		
		for (int i = 0; i<m; ++i) {
			string words;
			getline(cin, words);
			istringstream iss(words);
			string word;
			iss >> word;
			if (dictionary.find(word) != dictionary.end()) {
				cout << dictionary[word];
			} else {
				cout << word;
			}
			while (iss >> word) {
				if (dictionary.find(word) != dictionary.end()) {
					cout << " " << dictionary[word];
				} else {
					cout << " " << word;
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}
