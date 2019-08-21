#include <cstdio>
#include <vector>
#include <set>

using namespace std;

bool backtracking(vector<set<char> > & fframe, vector<set<char> > & lframe, char password[], int k, int & qnt, int N) {
	if (N == 5) {
		qnt++;
		if (qnt == k) {
			for (int i = 0; i < 5; ++i) {
				printf("%c", password[i]);
			}
			printf("\n");
			return true;
		}
		return false;
	}

	for (auto itf = fframe[N].begin(); itf != fframe[N].end(); ++itf) {
		for (auto itl = lframe[N].begin(); itl != lframe[N].end(); ++itl) {
			if ((*itf) == (*itl)) {
				password[N] = (*itf);
				if (backtracking(fframe, lframe, password, k, qnt, N+1)) return true;
			}
		}
	}

	return false;

}

bool solvePassword(vector<set<char> > & fframe, vector<set<char> > & lframe, int k) {
	int qnt = 0;
	char password[5];

	return backtracking(fframe, lframe, password, k, qnt, 0);
}

void printMatrix(vector<set<char> > & frame) {
	for (int i = 0; i < 5; ++i) {
		for (auto it = frame[i].begin(); it != frame[i].end(); ++it) {
			printf("%c", (*it));
		}
		printf("\n");
	}
	printf("\n");
}

int main() {

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
 		vector<set<char>> fframe(5, set<char>());
 		vector<set<char>> lframe(5, set<char>());

		int k;
		scanf("%d", &k);
		char ignore;
		for (int j = 0; j < 6; ++j) {
			scanf("%c", &ignore);
			for (int k = 0; k < 5; ++k) {
				char c;
				scanf("%c", &c);
				fframe[k].insert(c);
			}
		}

		//printMatrix(fframe);
		for (int j = 0; j < 6; ++j) {
			scanf("%c", &ignore);
			for (int k = 0; k < 5; ++k) {
				char c;
				scanf("%c", &c);
				lframe[k].insert(c);
			}
		}
		//printMatrix(lframe);

		if (!solvePassword(fframe, lframe, k)) printf("NO\n");
	}


}
