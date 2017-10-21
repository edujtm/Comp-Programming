#include <cstdio>
#include <vector>

#define MAXD 10010

using namespace std;

bool dominos[MAXD];
vector<vector<int> > derruba(MAXD, vector<int>()); 

void bfs(int domino, int & count) {

		if (dominos[domino]) {
			dominos[domino] = false;
			count++;
			for (int i = 0; i < (int) derruba[domino].size(); ++i) {
					bfs(derruba[domino][i], count);
			}
		}
}

int main() {
	
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m, l;
		scanf("%d %d %d", &n, &m, &l);
		for (int j = 1; j <= n; ++j) {
			derruba[j].clear();
		}
		for (int j = 1; j <= n; ++j) {
			dominos[j] = true;
		}	

		for (int j = 1; j <= m; ++j) {
			int x, y;
			scanf("%d %d", &x, &y);
			derruba[x].push_back(y);
		}
		
		int count = 0;
		for (int j = 1; j <= l; ++j) {
			int d;
			scanf("%d", &d);
			bfs(d, count);
		}
		printf("%d\n", count);
	}
}
