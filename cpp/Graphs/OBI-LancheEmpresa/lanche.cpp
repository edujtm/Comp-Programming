#include <cstdio>

#define MAXS 300
#define INFINITO 9999999

using namespace std;

void dijkstra(int distancia[], bool processado[], int matriz[MAXS][MAXS], int n, int v) {
	for (int i = 1; i <= n; ++i) {
		distancia[i] = matriz[v][i];
	}
	distancia[v] = 0;
	processado[v] = true;

	while (true) {

		int mids = -1;
		int menor = INFINITO;
		for (int i = 1; i <= n; ++i) {
			if (!processado[i] && distancia[i] < menor) {
				mids = i;
				menor = distancia[i];
			}
		}

		if (mids == -1) break;

		processado[mids] = true;

		for (int i = 1; i <= n; ++i) {
			distancia[i] = distancia[i] < distancia[mids] + matriz[mids][i] ? distancia[i] : distancia[mids] + matriz[mids][i];
		}
	}
}

int main() {
	int distancia[MAXS];
	bool processado[MAXS];
	int matriz[MAXS][MAXS];

	for (int i = 0; i < MAXS; ++i) {
			for (int j = 0; j < MAXS; ++j) {
				matriz[i][j] = INFINITO;
		       	}
	}

	int s, c;
	scanf("%d %d", &s, &c);

	for (int i = 0; i < c; ++i) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);


		matriz[a][b] = matriz[a][b] < d ? matriz[a][b] : d;
		matriz[b][a] = matriz[b][a] < d ? matriz[b][a] : d;
	}
	
	//Menor é o valor da menor distancia entre as salas que estão mais distantes
	// Menordist é o indice da sala em que foi colocada a cozinha e maiordist é o indice
	// de onde esta a sala mais distante da cozinha
	int menor = INFINITO; 
	// Procura em todas as salas
	for (int i = 1; i <= s; ++i) {
		// Definindo as menores distancias de cada sala para as outras
		for (int j = 1; j <= s; ++j) {
			processado[j] = false;
		}
		dijkstra(distancia, processado, matriz, s, i);
		int maior = -1;
		// Qual a sala que possui a maior distancia
		for (int j = 1; j <= s; ++j) {
			if (maior < distancia[j]) {
				maior = distancia[j];
			}
		}

		// e se a maior distancia dessa sala for menor que a maior distancia atual, atualiza o valor
		if (menor > maior) {
			menor = maior;
		}
	}

	printf("%d\n", menor);

}
