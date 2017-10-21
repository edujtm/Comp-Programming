#include <cstdio>
#include <set>

#define MAXC 540
#define INFINITO 99999

using namespace std;

int dijsktra(int distancia[], bool processado[], int matriz[MAXC][MAXC], int n, int v, int d) {
	for (int i = 1; i <= n; ++i) {
		processado[i] = false;
		distancia[i] = matriz[v][i];
	}

	processado[v] = true;
	distancia[v] = 0;

	while (true) {
		int midc = -1;
		int menor = INFINITO;

		for (int i = 1; i <= n; ++i) {
			if (!processado[i] && menor > distancia[i]) {
				menor = distancia[i];
				midc = i;
			}
		}

		if (midc == -1) {
			return -1;
			break;
		}

		if (midc == d) return distancia[midc] == INFINITO ? -1 : menor;

		processado[midc] = true;

		for (int i = 1; i <= n; ++i) {
			distancia[i] = distancia[i] < distancia[midc] + matriz[midc][i] ? distancia[i] : distancia[midc] + matriz[midc][i];
		}
	}
}


int main() {
	bool processado[MAXC];
	int distancia[MAXC];
	int matriz[MAXC][MAXC];
	int instant[MAXC][MAXC];

	int n, e;

	while (scanf("%d %d", &n, &e) && (n != 0 || e != 0)) {
		for (int i = 0; i <= n+1; ++i) {
			for (int j = 0; j <= n+1; ++j) {
				matriz[i][j] = INFINITO;
				instant[i][j] = false;
			}
		}
		for (int i = 1; i <= e; ++i) {
			int x, y, h;
			scanf("%d %d %d", &x, &y, &h);

			matriz[x][y] = matriz[x][y] < h ? matriz[x][y] : h;
			if (matriz[y][x] != INFINITO) {
				matriz[x][y] = 0;
				matriz[y][x] = 0;
				instant[x][y] = true;
				instant[y][x] = true;
			}
		}

		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; ++i) {
			int o, d;
			scanf("%d %d", &o, &d);
			if (instant[o][d]) {
				printf("0\n");
			} else {
				int result = dijsktra(distancia, processado, matriz, n, o, d);
				if (result != -1) {
					printf("%d\n", result);
				} else {
					printf("Nao e possivel entregar a carta\n");
				}			
			}
		}
		printf("\n");
	}
}
