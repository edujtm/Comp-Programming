//Problema dificil, colei a resposta do site do noic.
//Acredito que tenha um jeito mais simples de fazer calculando as diferenças entre os horários
//Solved
#include <cstdio>

#define MAXT 1000100
#define MAXC 10
#define MAXN 1000
#define MAXF 20000

int chegada[MAXN];
int tempo[MAXN];
int livre[MAXC];
int fila[MAXN];

int main() {
	int  fim = -1, ini = 0;
	int c, n, resposta = 0, prox = 0;

	scanf("%d %d", &c, &n);

	for(int i = 0; i < n; ++i) {
		if (i < MAXC) livre[i] = 0;
		scanf("%d %d", &chegada[i], &tempo[i]);
	}
	
	for (int min = 0; min < MAXF; ++min) {
		while (chegada[prox] == min && prox < n) {
			fila[++fim] = prox++;
		}

		bool vaga = true;

		while (fim-ini+1 > 0 && vaga) {
			vaga = false;
			for (int j = 0; j < c; ++j) {
				if (livre[j] <= min) {
					if (min - chegada[fila[ini]] > 20) resposta++;
					livre[j] = min + tempo[fila[ini]];
					ini++;
					vaga = true;
					break;
				}
			}
		}

		if (fim - ini + 1 == 0 && prox == n) break;
	}

	printf("%d\n", resposta);
	return 0;
}
