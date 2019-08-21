#include <string>
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

#define MAXS 10100
#define MAXP 110

using namespace std;

bool compara(const pair<string, set<string>> & x, const pair<string, set<string>> & y) {
	if (x.second.size() > y.second.size()) return true;
	if (x.second.size() < y.second.size()) return false;
	if (x.first < y.first) return true;
	return false;
}

int main() {
	string word;
	int i = 0;
	set<string> st;
	pair<string, set<string>> proj[MAXP];
	while (getline(cin, word)) {
		if (word == "0") {
			break;
		} else if (word == "1") {
			sort(proj, proj+i, compara);
			for (int j = 0; j < i; j++) {
				cout << proj[j].first << " " << proj[j].second.size() << endl;
				proj[j].second.clear(); 
			}
			i = 0;
			st.clear();
		} else if (word[0] >= 'A' && word[0] <= 'Z') {
			proj[i++].first = word;
		} else {
			if ((st.insert(word)).second == true) {
				proj[i-1].second.insert(word);
			} else {
				for (int j = 0; j < i-1; j++) {
					proj[j].second.erase(word);
				}
			} 
		}
	}
}
