#include <cstdio>

#define MAXC 150
#define INFINITO 9999999

using namespace std;

int dijsktra(int distancia[], bool processado[], int matriz[MAXC][MAXC], int n, int v) {
	for (int i = 0; i < n; ++i) {
		distancia[i] = matriz[v][i];
		processado[i] = false;
	}

	processado[v] = true;
	distancia[v] = 0;

	int maior;	
	while (true) {
		int midc = -1;
		int menor = INFINITO;

		for (int i = 0; i < n; ++i) {
			if (!processado[i] && distancia[i] < menor) {
				menor = distancia[i];
				midc = i;
			}
		}

		if (midc == -1) break;

		processado[midc] = true;

		maior = -1;
		for (int i = 0; i < n; ++i ) {
			distancia[i] = distancia[i] < distancia[midc] + matriz[midc][i] ? distancia[i] : distancia[midc] + matriz[midc][i];
			if (maior < distancia[i]) maior = distancia[i];
		}
	}

	return maior;
}

int main() {
	int matriz[MAXC][MAXC];
	bool processado[MAXC];
	int distancia[MAXC];

	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			matriz[i][j] = INFINITO;
		}
	}

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		matriz[u][v] = matriz[u][v] < w ? matriz[u][v] : w;
		matriz[v][u] = matriz[v][u] < w ? matriz[v][u] : w;
	}

	int menor = INFINITO;
	for (int i = 0; i < n; ++i) {
		int maiordist = dijsktra(distancia, processado, matriz, n, i);

		if (menor > maiordist) {
			menor = maiordist;
		}
	}

	printf("%d\n", menor);
}
