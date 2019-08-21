#include <cstdio>

#define MAXN 100100

using namespace std;

int buscab(int numbers[], int n, int query) {
	int ini = 0, fim = n-1, index = -1;	

	while (ini <= fim) {
		int meio = (ini + fim) / 2;
		
		if (numbers[meio] == query) {
			index = meio;
			break;
		}
		if (numbers[meio] > query) fim = meio-1;
		if (numbers[meio] < query) ini = meio+1;
	}
	if (index != -1) {
		while (index > 0 && numbers[index] == numbers[index-1]) --index;
	}
	return index;
}

int main() {

	int numbers[MAXN];
	int n, q;
	scanf("%d %d", &n, &q);

	for (int i = 0; i < n; ++i) {
		int value;
		scanf("%d", &value);
		numbers[i] = value;
	}

	for (int i = 0; i < q; ++i) {
		int query;
		scanf("%d", &query);
		printf("%d\n", buscab(numbers, n, query));
	}
}
