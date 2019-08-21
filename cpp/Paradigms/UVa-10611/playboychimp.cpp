#include <cstdio>

#define MAXC 50050

using namespace std;

int tallestLessThan(int ladies[], int size, int height) {
	int ini = 0, fim = size-1, maior_index = -1;

	while (ini <= fim) {
		int meio = (ini + fim) / 2;

		if (ladies[meio] < height) {
			ini = meio+1;
			maior_index = meio;
		}

		if (ladies[meio] >= height) fim = meio-1; 
		
	}

	return maior_index;
}

int shortestBiggerThan(int ladies[], int size, int height) {
	int ini = 0, fim = size-1, menor_index = -1;

	while (ini <= fim) {
		int meio = (ini + fim) / 2;

		if (ladies[meio] > height) {
			fim = meio-1;
			menor_index = meio;
		}

		if (ladies[meio] <= height) ini = meio+1; 
		
	}

	return menor_index;
}

int main() {

	int n;
	scanf("%d", &n);
	int ladies[MAXC];

	for (int i = 0; i < n; ++i) {
		int c;
		scanf("%d", &c);
		ladies[i] = c;
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int height;
		scanf("%d", &height);

		int tallest = tallestLessThan(ladies, n, height);
		int shortest = shortestBiggerThan(ladies, n, height);
		if (tallest != -1) {
			printf("%d ", ladies[tallest]);
		} else {
			printf("X ");
		}
		if (shortest != -1) {
			printf("%d\n", ladies[shortest]);
		} else {
			printf("X\n");
		}
	}
}
