#include <cstdio>
#include <vector>
#include <queue>

#define MAXN 15
#define INFINITO 99999

using namespace std;

int norte(int xi) {
	return 4 * xi;
}

int sul(int xi) {
	return 4 * xi + 1;
}

int oeste(int xi) {
	return 4 * xi + 2;
} 

int leste(int xi) {
	return 4 * xi + 3;
}

int bfs(int distancia[MAXN][MAXN], int matriz[4*MAXN][MAXN], int n, int xi, int yi, int xf, int yf) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++ j) {
			distancia[i][j] = -1;
		}

	}
	queue<pair<int, int> > processados;
	processados.push(make_pair(xi, yi));
	distancia[xi][yi] = 0;

	while (processados.size() > 0) {
		pair<int, int> atual = processados.front();
		processados.pop();
		if (atual.first == xf && atual.second == yf) return distancia[xf][yf];
		if (atual.second+1 < n && distancia[atual.first][atual.second+1] == -1 && matriz[norte(atual.first)][atual.second]) {
		       	processados.push(make_pair(atual.first, atual.second+1));
			if (distancia[atual.first][atual.second+1] == -1) distancia[atual.first][atual.second+1] = distancia[atual.first][atual.second]+1;
		}
		if (atual.second-1 >= 0 && distancia[atual.first][atual.second-1] == -1 &&  matriz[sul(atual.first)][atual.second]) {
		       	processados.push(make_pair(atual.first, atual.second-1));
			if (distancia[atual.first][atual.second-1] == -1) distancia[atual.first][atual.second-1] = distancia[atual.first][atual.second]+1;
		}
		if (atual.first-1 >= 0 && distancia[atual.first-1][atual.second] == -1 && matriz[oeste(atual.first)][atual.second]) {
		       	processados.push(make_pair(atual.first-1, atual.second));
			if (distancia[atual.first-1][atual.second] == -1) distancia[atual.first-1][atual.second] = distancia[atual.first][atual.second]+1;
		}
		if (atual.first+1 < n && distancia[atual.first+1][atual.second] == -1 && matriz[leste(atual.first)][atual.second]) {
		       	processados.push(make_pair(atual.first+1, atual.second));
			if (distancia[atual.first+1][atual.second] == -1) distancia[atual.first+1][atual.second] = distancia[atual.first][atual.second]+1;
		}
	}

	return -1;
}

int main() {
	int distancia[MAXN][MAXN];
	int matriz[4*MAXN][MAXN];

	int n;

	while (scanf("%d", &n) && n != 0) {

		for (int i = n-1; i >= 0; --i) {
			for (int j = 0; j < 4*n  ; ++j) {
				int possivel;
				scanf("%d", &possivel);
				matriz[j][i] = possivel;
			}
		}

		int p;
		scanf("%d", &p);
		for (int i = 0; i < p; ++i) {
			int xi, yi, xf, yf;
			scanf("%d %d %d %d", &xi, &yi, &xf, &yf);
			int result = bfs(distancia, matriz, n, xi, yi, xf, yf);
			if (result != -1) {
				printf("%d\n", result);
			} else {
				printf("Impossible\n");
			}
		}
		printf("\n");

	}
}
