#include <cstdio>
#include <vector>

#define MAXP 35

void backtracking(std::vector<bool> & primes, int sequence[], bool usados[], int n, int pos) {
	if (pos == n) {
		if (!primes[sequence[n-1] + 1]) return; // Soma do ultimo com o primeiro não é primo
		printf("%d", sequence[0]);
		for (int i = 1; i < n; ++i) {
			printf(" %d", sequence[i]);
		}
		printf("\n");
		return;
	} 

	for (int i = 2; i <= n; ++i) {
		sequence[pos] = i;

		if (!usados[i]) {
			usados[i] = true;
			int index = sequence[pos] + sequence[pos-1];
			if (primes[index]) {
				backtracking(primes, sequence, usados, n, pos+1);
			}
			usados[i] = false;
		}
	}
	return;
}

void solvePrimeCircle(std::vector<bool> & primes, int n) {
	int sequence[40];
	bool usados[40];
	for (int i = 0; i < 40; ++i) {
		sequence[i] = 0;
		usados[i] = false;
	}
	sequence[0] = 1;
	usados[1] = true;

	backtracking(primes, sequence, usados, n, 1);
}

int main() {
	std::vector<bool> primes(MAXP, true);

	// Calcula crivo
	for (int i = 2; i < MAXP; ++i) {
		if (primes[i] == true) {
			for (int j = 2*i; j < MAXP; j += i) {
				primes[j] = false;
			}
		}
	}
	
	/*for (int i = 2; i < MAXP; ++i) {
		if (primes[i]) printf("%d ", i);
	}
	printf("\n");
	*/
	
	int n, count = 1;
	while (scanf("%d", &n) == 1) {
		if (count-1) printf("\n");
		printf("Case %d:\n", count);
		solvePrimeCircle(primes, n);
		count++;
	}

	return 0;
}
