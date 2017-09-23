#include <iostream>
#include <vector>
#include <algorithm>

#define MAXW 1000

double grades[MAXW]

bool compara(int n1, int n2) {
	return grades[n1] > grades[n2];
}

int main() {
	int n;

	cin >> n
	for (int i = 0; i < n; i++) {

		int ip[MAXW];
		int fp[MAXW];
		int a, diff;

		cin >> a;

		for (int j = 0; j < a; j++) {
			ip[j] = j;
			fp[j] = j;
			cin >> grades[j];
		}

		std::sort(fp, fp + a, compara);

		for (int j = 0; j < a; j++) {
			if ( ip[i] == fp[i] ) ++diff;
		}

		cout << diff << endl;
	}
}
