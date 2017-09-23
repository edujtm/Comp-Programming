#include <list>
#include <iostream>
#include <string>

#define MAXP 1000100
#define MAXT 1020

using namespace std;

int main() {
	list<int>::iterator last[MAXT];
	list<int> queue;
	int t, k = 1;
	while (cin >> t && t != 0) {
		int size[MAXT] = {0};
		int teamOf[MAXP] = {-1};
		for (int i = 0; i < t; i++) {
			int n;
			cin >> n;
			for (int j = 0; j < n; ++j) {
				int p;
				cin >> p;
				teamOf[p] = i;
			}
		}
		string f;
		cout << "Scenario #" << k << endl;
		while (cin >> f && f != "STOP") {
			if (f == "ENQUEUE") {
				int element;
				cin >> element;
				if (size[teamOf[element]] == 0) {
					queue.push_back(element);
					list<int>::iterator it = queue.end();
					--it;
					last[teamOf[element]] = it;
					size[teamOf[element]]++;
				} else {
					last[teamOf[element]]++;
					size[teamOf[element]]++;
					list<int>::iterator it = last[teamOf[element]];
					queue.insert(it, element);
					last[teamOf[element]]--;
				}
			} else if (queue.size() > 0 && f == "DEQUEUE") {
				size[teamOf[queue.front()]]--;
				cout << queue.front() << endl;
				queue.pop_front();
			}
			cin.ignore();
		}
		queue.clear();
		k++;
		cin.ignore();
		cout << endl;
	}
}
