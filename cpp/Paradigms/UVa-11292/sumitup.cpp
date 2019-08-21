#include <cstdio>

#define MAXN 30

using namespace std;

void backtracking(bool usados[], int sum[], int values[], int input[], int t, int n, int place, int & result, int qnt) {

	// input está indexado de 0 a n
	// sum está indexado de 0 a n inclusive, sendo sum[0] = 0
	// usados esta indexado de 0 a n
	// values esta indexado de 1 a n inclusive

	if (qnt != 0 && sum[qnt] == t) {
		printf("%d", values[1]);
		for (int i = 2; i <= qnt; ++i) {
			printf("+%d", values[i]);
		}
		printf("\n");
		result++;
		return;
	}

	if (qnt == n) return;

	for (int i = place+1; i < n; ++i) {
		sum[qnt+1] = input[i] + sum[qnt];

		if (sum[qnt+1] > t || usados[i]) continue;

		values[qnt+1] = input[i];
		usados[i] = true;
		backtracking(usados, sum, values, input, t, n, i, result, qnt+1);
		usados[i] = false;
		while (input[i+1] == input[i]) ++i;
	}

}

int solveSum(int input[], int t, int n) {
	bool usados[MAXN];
       	int sum[MAXN], values[MAXN];
	int result = 0;
	sum[0] = 0;

	for (int i = 0; i < n; ++i) {
		usados[i] = false;
	}
	for (int i = 0; i < n; ++i) {
		values[1] = input[i];
		sum[1] = input[i];
		backtracking(usados, sum, values, input, t, n, i, result, 1);
		usados[i] = true;
		while (input[i+1] == input[i]) {
			usados[++i] = true;
		}
	}
	return result;
}

int main() {

	int input[MAXN]; 

	int t, n;
	while (scanf("%d %d", &t, &n) && n != 0) {
		for (int i = 0; i < n; ++i) {
			int v;
			scanf("%d", &v);
			input[i] = v;
		}

		printf("Sums of %d:\n", t);
		int qntresult = solveSum(input, t, n);
		if (qntresult == 0) {
			printf("NONE\n");
		}
	}
}
