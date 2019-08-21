#include <iostream>
#include <string>
#include <map>

#define MAXB 1000100


using namespace std;

int main () {

	int n;
	while (cin >> n && n != 0 ) {
		cin.ignore();
		map<int,int> bills;
		int total = 0;
		for (int i = 0; i < n; ++i) {	
			int k;
			cin >> k;
			for (int j = 0; j < k; ++j) {
				int b;
				cin >> b;
				bills[b]++;
			}
			if (bills.size() > 0) {
				map<int, int>::iterator itmin = bills.begin();
				map<int, int>::iterator itmax = bills.end();
				itmax--;
				total += (*itmax).first - (*itmin).first;
				itmin->second--;
				itmax->second--;
				if ((*itmin).second == 0) bills.erase(itmin);
				if (bills.size() > 0 && (*itmax).second == 0) bills.erase(itmax);
			} 
		}
		cout << total << endl;
	}
}s
