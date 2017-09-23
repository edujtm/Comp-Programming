#include <set>
#include <iostream>

#define MAXM 30100

using namespace std;

int main() {
	multiset<int> blkbox;
	int m, n, k;
	int a[MAXM], u[MAXM];
	cin >> k;
	//cin.ignore();
	for (int b = 0; b < k; ++b) {
		//cin.ignore();
		cin >> m >> n;
		//cin.ignore();
		for (int i = 0; i < m; ++i) {
			cin >> a[i];	
		}
		for (int i = 0; i < n; ++i) {
			cin >> u[i];
		}
		int j = 1;
		blkbox.clear();
		// O iterador it estava prendendo no blkbox.end() e não queria mais voltar para valores anteriores
		// O jeito que consegui impedir que isso aconteça foi colocando valores invalidos no set
		blkbox.insert(2000000001);
		blkbox.insert(2000000001);
		blkbox.insert(a[0]);
		auto it = blkbox.begin();
		for (int i = 0; i <n; ++i) {
			while (u[i] > (int) blkbox.size() - 2) {
				blkbox.insert(a[j]);
				if (it != blkbox.begin() && a[j] < *it) it--;
				j++;
			}
			cout  << *it << endl; 
			it++;
		}
		if (b != k-1) cout << endl;
	}
}

