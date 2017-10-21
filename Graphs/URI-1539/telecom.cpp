#include <cstdio>
#include <vector>
#include <cmath>

#define MAXA 110
#define INFINITO 99999

using namespace std;

struct antena {

	int x;
	int y;
	int r;

	double distancia (const antena & rhs) {
		return sqrt(pow(rhs.x - x, 2) + pow(rhs.y - y, 2));
	}

	bool alcanca(const antena & rhs) {
		return sqrt(pow(rhs.x - x, 2) + pow(rhs.y - y, 2)) <= r;
	}
};

void dijsktra(double adj[MAXA][MAXA], bool processado[], double distancia[], int n, int v ) {
	for (int i = 0; i < n; ++i) {
		distancia[i] = adj[v][i];
		processado[i] = false;
	}
	distancia[v] = 0;
	processado[v] = true;

	while (true) {
		int otherv = -1;
		int menor = INFINITO;

		for (int i = 0; i < n; ++i) {
			if (!processado[i] && distancia[i] < menor) {
				menor = distancia[i];
				otherv = i;
			}
		}

		if (otherv == -1) break;

		processado[otherv] = true;

		for (int i = 0; i < n; ++i) {
			distancia[i] = distancia[i] < distancia[otherv] + adj[otherv][i] ? distancia[i] : distancia[otherv] + adj[otherv][i];
		}
	}

}

int main() {

	vector<antena> antenas;
	double adj[MAXA][MAXA];
	bool processado[MAXA];
	double distancia[MAXA];

	int n;
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; ++i) {
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			antena input {x, y, r};
			antenas.push_back(input);
		}

		for (int i = 0; i < (int) antenas.size(); ++i) {
			for (int j = 0; j < (int) antenas.size(); ++j) {
				if (i == j) {
					adj[i][j] = 0;
				} else if (antenas[i].alcanca(antenas[j])) {
					adj[i][j] = antenas[i].distancia(antenas[j]);
				} else {
					adj[i][j] = INFINITO;
				}
			}
		}

		int c;
		scanf("%d", &c);
		for (int i = 0; i < c; ++i) {
			int a1, a2;
			scanf("%d %d", &a1, &a2);
			a1--;
			a2--;
			dijsktra(adj, processado, distancia, n, a1);
			if (distancia[a2] == INFINITO) {
				printf("-1\n");
			} else {
				printf("%d\n", (int) trunc(distancia[a2]));
			}
		}
		antenas.clear();
	}	
}
