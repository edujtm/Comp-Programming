#include <cstdio>
#include <vector>

#define MAXV 10010
#define INFINITO 99999

using namespace std;

void dijsktra(vector<vector<int> > & adj, bool processado[], int distancias[], int n, int v) {
	for (int i = 0; i < n; ++i) {
		distancias[i] = adj[v][i];
		processado[i] = false;
	}
	distancias[v] = 0;
	processado[v] = true;

	while (true) {
		int otherv = -1;
		int menor = INFINITO;

		for (int i = 0; i < n; ++i) {
			if (!processado[i] && distancias[i] < menor) {
				menor = distancias[i];
				otherv = i;
			}
		}

		if (otherv == -1) break;

		processado[otherv] = true;

		for (int i = 0; i < n; ++i) {
			distancias[i] = distancias[i] < distancias[otherv] + adj[otherv][i] ? distancias[i] : distancias[otherv] + adj[otherv][i];
		}
	}
}

int main() {

	bool processado[MAXV];
	int distancias[MAXV];

	int test;
	
	scanf("%d", &test);

	for (int i = 0; i < test; ++i) {
		vector<vector<int> > adj;
		int v, e;
		scanf("%d %d", &v, &e);

		for (int j = 0; j < v; ++j) {
			adj.push_back(vector<int>());
			for (int k = 0; k < v; ++k) {
				adj[j].push_back(INFINITO);
			}
		}

		for (int j = 0; j < e; ++j) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			b--;	
			a--;
			
			adj[a][b] = c < adj[a][b] ? c : adj[a][b];
		}

		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--;
		v2--;
		dijsktra(adj, processado, distancias, v, v1);
		if (distancias[v2] != INFINITO) {
			printf("%d\n", distancias[v2]);
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
