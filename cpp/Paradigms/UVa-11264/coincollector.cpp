#include <cstdio>

#define MAXC 1010

using namespace std;

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int coins[MAXC];
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &coins[i]);
		int maior = coins[0];
		int coin = 1; // Primeira moeda sempre pode ser retirada
		for (int i = 1; i < n-1; ++i) {
			if (maior+coins[i] < coins[i+1]) {
				maior += coins[i];
				coin++;
			}
		}
		coin++; // Ultima moeda tambem sempre pode ser retirada
		printf("%d\n", coin);
	}

	return 0;
}
