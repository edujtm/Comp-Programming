#include <cstdio>

#define MAXT 51
#define MAXN 1000010

using namespace std;

int qnts[MAXT][MAXN], m = 1, n = 1000000, t, mod = 1e9 +7;

int recursive(int pos, int nivel) {
	if (qnts[pos][nivel] == -1) {
		int qnt = 0;
			if (nivel < n) qnt += recursive(pos-1, nivel+1);
			if (nivel > m) qnt += recursive(pos-1, nivel-1);
		qnts[pos][nivel] = qnt % mod;
		return qnt % mod;
	} else {
		return qnts[pos][nivel];
	}
}

int main() {
	for (int i = 0; i < MAXN; ++i) {
		qnts[0][i] = -1;
		qnts[1][i] = 1;
	}
	for (int i = 2; i < MAXT; ++i) {
		for (int j = 0; j < MAXN; ++j) {
			qnts[i][j] = -1;
		}
	}
	scanf("%d %d %d", &t, &m, &n);
	int result = 0;
	for (int i = m; i <= n; ++i) {
		result = (result + recursive(t, i)) % mod;
	}
	printf("%d\n", result);
}
