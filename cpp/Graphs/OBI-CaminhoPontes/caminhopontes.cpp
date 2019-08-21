#include<cstdio> 

#define MAXN 1010
#define INFINITO 99999999

void dijkstra(int buracos[], bool processado[], int matriz[MAXN][MAXN], int n, int v) {
	for (int i = 0; i < n+1; ++i) {
		buracos[i] = matriz[v][i];
	}
	buracos[v] = 0;
	processado[v] = true;

	while (true) {
		int midv = -1;
		int menor = INFINITO;	
		// Escolhe o vertice que possui a menor distancia e ainda não foi processado
		for (int i = 0; i <= n+1; ++i) {
			if (!processado[i] && buracos[i] < menor) {
				midv = i;
				menor = buracos[i];
			}
		}

		// Caso não encontre um vertice ou todos os vertices já estejam processados, sai do while
		if (midv == -1) break;

		processado[midv] = true;
		
		// Atualiza o valor da distancia levando em consideração a distancia atual do ponto v ate o i e a distancia
		// do ponto v para o midv mais a distancia do midv para i. 
		for (int i = 0; i <= n+1; ++i) {
			buracos[i] = buracos[i] < buracos[midv] + matriz[midv][i] ? buracos[i] : buracos[midv] + matriz[midv][i];
		}
	}
}

int main() {
	bool processado[MAXN];
	int matriz[MAXN][MAXN];
	int buracos[MAXN];
	
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n+1; ++i) {
		for (int j = 0; j <= n+1; ++j) {
			matriz[i][j] = INFINITO;
		}
	}

	for (int i = 0; i < m; ++i) {
		int s, t, b;
		scanf("%d %d %d", &s, &t, &b);

		matriz[s][t] = b < matriz[s][t] ? b : matriz[s][t];
		matriz[t][s] = b < matriz[t][s] ? b : matriz[t][s];
	}

	dijkstra(buracos, processado, matriz, n, 0);
	printf("%d\n", buracos[n+1]);

	return 0;
}
