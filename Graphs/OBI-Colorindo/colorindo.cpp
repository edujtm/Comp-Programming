#include <cstdio>
#include <vector>

#define MAXM 202

using namespace std;

void dfs(vector<vector<int> > & desenho, int x, int y, int & value) {
	for (int i = x-1; i <= x+1; ++i) {
		for (int j = y-1; j <= y+1; ++j) {
			if (desenho[i][j] == -1) {
				desenho[i][j] =  1;
				value += 1;
			       dfs(desenho, i, j, value);	
			}
		}
	}
}

int main() {
	vector<vector<int> > desenho(MAXM, vector<int>(MAXM, -1));
	int n, m, x, y, k;
	char ignore;
	scanf("%d %d %d %d %d%c", &n, &m, &x, &y, &k, &ignore);
	// retira as linhas auxiliares do topo e final, pois fiz a matrix com espaços a mais para evitar checagem de ArrayOutOfBounds
	for (int i = 0; i <= m+1; ++i) {
		desenho[0][i] = 1;
		desenho[n+1][i] = 1;
	}

	for (int i = 1; i < n+1; ++i) {
		desenho[i][0] = 1;
		desenho[i][m+1] = 1;	
	}
	for (int i = 0; i < k; ++i) {
		int a, b;
		scanf("%d %d%c", &a, &b, &ignore);
		desenho[a][b] = 1;
	}
	int value = 1;
	desenho[x][y] = 1;
	dfs(desenho, x, y, value);

	printf("%d\n", value);
	/*for (int i = 0; i <= n+1; ++i) {
		for (int j = 0; j <= m+1; ++j) {
			printf("%d ", desenho[i][j]);
		}
		printf("\n");
	}*/
}
