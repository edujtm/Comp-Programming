#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

#define MAXR 100

using namespace std;

int main() {

	int t;
	cin >> t;
	cin.ignore();

	for (int i = 0; i<t; ++i) {
		string title;
		int m, n, bdg;
		
		getline(cin, title);
		cin >> m >> n >> bdg;
		cin.ignore();
		for (int j = 0; j < title.size(); ++j) {
			if (title[j] >= 'a' && title[j] <= 'z') {
				title[j] -= 32;
			}
		}

		cout << title << endl;
		map<string, int> ingredients;
		vector <pair<int, string> > recipes;
		for (int j = 0; j < m; ++j) {
			string ingredient;
			int c;
			cin >> ingredient >> c;
			cin.ignore();
			ingredients[ingredient] = c;
		}

		for (int j = 0; j < n; ++j ) {
			string recipe;
			int req;
			getline(cin, recipe);
			recipes.push_back(make_pair(0, recipe));
			cin >> req;
			cin.ignore();
			for (int k = 0; k < req; ++k) {
				string require;
				int qnt;
				cin >> require >> qnt;
				cin.ignore();
				recipes[j].first += ingredients[require] * qnt;
			}
		}

		sort(recipes.begin(), recipes.end());

		bool valid = false;
		for (int j = 0; j < recipes.size(); ++j) {
			if (recipes[j].first < bdg) {
				cout << recipes[j].second << endl;
				valid = true;
			}
		}
		if (!valid) cout << "Too expensive!" << endl;
		cout << endl;
	}	

}
