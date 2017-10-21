#include <cstdio>
#include <vector>

#define MAXP 10010

using namespace std;

bool divideQnt(int paes[], int k, int n, int tam) {
	int sum = 0;
	for (int i = 0; i < k; ++i) {
		sum += (paes[i] / tam);
	}
	if (sum >= n) {
		return true;
	} 
	return false;
	
}

int findPeak(int paes[], int k, int n) {
	int ini = 0, fim = MAXP+1;
	int sol = 0;

	while (ini <= fim) {
		int meio = (ini + fim) / 2;

		if (divideQnt(paes, k, n, meio)) {
			sol = meio;
			ini = meio+1;
		} else {
			fim = meio-1;
		}
	}

	return sol;
}

int main() {

	int n, k, paes[MAXP];
	scanf("%d", &n);
	scanf("%d", &k);

	for (int i = 0; i < k; ++i) {
		int p;
		scanf("%d", &p);
		paes[i] = p;
	}

	int sol = 0;
	sol = findPeak(paes, k, n);
	printf("%d\n", sol);

}
