#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

	int m, n;
	cin >> m >> n;
	map<string, int> dic;
	for (int i = 0; i < m; i++) {
		string word;
		int value;
		cin >> word >> value;
		dic[word] = value;
	}
	
	for (int i = 0; i <n; i++) {
		string words;
		int haypoints = 0;
		while (cin >> words) {
			if (words == ".") break;
			if (dic.find(words) != dic.end()) {
				haypoints += dic[words];
			}
		}
		cout << haypoints << endl;
	}
}
