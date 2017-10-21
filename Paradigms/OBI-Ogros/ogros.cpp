#include <cstdio>

#define MAXN 10010

using namespace std;

int findPremio(int premio[], int bound[], int n, int x) {
	int ini = 0, fim = n-1, menor_index;

	while (ini <= fim) {

		int meio = (ini + fim) / 2;

		if (bound[meio] <= x) {

			ini = meio+1;
			menor_index = meio;
		}

		if (bound[meio] > x) fim = meio-1; 
	}

	return premio[menor_index];
}

int main() {

	int m, n;
	int premio[MAXN], bound[MAXN];

	bound[0] = 0;

	scanf("%d %d", &n, &m);

	for (int i = 1; i < n; ++i) {
		int b;
		scanf("%d", &b);
		bound[i] = b;
	}

	for (int i = 0; i < n; ++i) {
		int p;
		scanf("%d", &p);
		premio[i] = p;
	}

	for (int i = 0; i < m; ++i) {
		int ogro;
		scanf("%d", &ogro);
		if (i == 0) {
			printf("%d", findPremio(premio, bound, n, ogro));
		} else {
			printf(" %d", findPremio(premio, bound, n, ogro));
		}
		if (i == m-1) printf("\n");
	}

}
