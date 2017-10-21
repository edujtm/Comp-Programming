#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXH 20100

using namespace std;

int shortestTallerThan(int knights[], bool valid[], int m, int diam) {
	int ini = 0, fim = m-1, index = -1;

	while (ini <= fim) {
		int meio = (fim + ini) / 2;

		if (knights[meio] >= diam) {
			index = meio;
			fim = meio-1;
		} else {
			ini = meio+1;
		}
	}
	
	if (index != -1) {
		while(index < m && !valid[index]) ++index;
		if (index < m) {
			valid[index] = false;
		} else {
			index = -1;
		}
	}
	return index;
}

int main() {

	int n, m;
	while (scanf("%d %d", &n, &m) && n != 0 && m != 0) {
		int heads[MAXH];
		int knights[MAXH];
		bool valid[MAXH];
	
		for (int i = 0; i < m; ++i) valid[i] = true;
		for (int i = 0; i < n; ++i) scanf("%d", &heads[i]);
		for (int i = 0; i < m; ++i) scanf("%d", &knights[i]);

		sort(knights, knights+m);

		int qnt = 0;
		int value = -1;
		for (int i = 0; i < n; ++i) {
			value = shortestTallerThan(knights, valid, m, heads[i]);
			if (value != -1) {
				qnt += knights[value];
			} else {
				// Se não encontrar cavaleiro
				printf("Loowater is doomed!\n");
				break;
			}
		}
		if (value != -1) {
			printf("%d\n", qnt);
		}
	}

}
