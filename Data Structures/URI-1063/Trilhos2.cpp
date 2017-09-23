#include <cstdio>

using namespace std;

#define MAXT 30

char entrada[MAXT];
char saida[MAXT];

struct pilha {

	int tam = 0;
	char trains[MAXT];

	void pop() { if (tam > 0) tam--;}

	void push(int t) { trains[tam++] = t;}

	int top() { return trains[tam-1];}

	void clear() {tam = 0;}
};

int main() {
	
	int n;
	char ignore;
	pilha estacao;

	scanf("%d", &n);
	while ( n != 0 ) {
		int t = 0;
		bool valid = true;
		estacao.clear();
		for (int i = 0; i < n; ++i) {
			scanf(" %c", &entrada[i]);
		}

		scanf("%c", &ignore);
		for (int i = 0; i < n; ++i) {
			scanf(" %c", &saida[i]);
		}
		scanf("%c", &ignore);

		for (int i = 0; i < n; ++i) {
			if (estacao.tam > 0 && saida[i] == estacao.top()) {
				estacao.pop();
				printf("R");
			} else if (t < n && (estacao.tam == 0 || saida[i] != estacao.top())) {
				estacao.push(entrada[t++]);
				printf("I");				
				while (t < n && estacao.top() != saida[i]) {
					estacao.push(entrada[t++]);
					printf("I");
				}
				if (estacao.tam > 0 && estacao.top() == saida[i]) {
					estacao.pop();
					printf("R");
				} else {
					i--;
				}
			} else if (t == n && (estacao.tam == 0 || estacao.top() != saida[i])) {
				valid = false;
				break;
			}
		}
		if (!valid) {
			printf(" Impossible");
		}
		printf("\n");
		scanf("%d", &n);
	}
}
