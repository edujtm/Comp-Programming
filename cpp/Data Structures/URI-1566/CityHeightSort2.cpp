#include <cstdio>

#define MAXP 3000000
#define MAXS 230

using namespace std;

int n, valor, aux[MAXS];

int main() {
	
	int nc;

	scanf("%d", &nc);

	for (int i = 0; i< nc; ++i) {
		scanf("%d", &n);

		for (int j = 0; j < MAXS; ++j) aux[j] = 0;

		for (int j = 0; j < n; ++j) {
			scanf("%d", &valor);
			++aux[valor - 20];
		}

		int j = 0;
		while (aux[j] == 0) {
			j++;
		}
		printf("%d", j+20);
		aux[j]--;
		for (; j <= 210; j++) {
			while (aux[j] > 0) {
				printf(" %d", j+20);
				aux[j]--;
			}
		}
		printf("\n");
	}

}
