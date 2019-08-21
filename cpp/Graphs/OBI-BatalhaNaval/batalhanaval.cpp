#include <cstdio>
#include <vector>
#include <map>

#define MAXT 110

using namespace std;

void dfs(vector<vector<int> > & tab, int x, int y, bool & valid) {
	if (tab[x][y] == -1) return;

	//Verifica se a posição é um barco destruido ou ainda inteiro
	if (tab[x][y] == 2 || tab[x][y] == 1) {
		// se o barco ainda tiver uma parte inteira, a variavel valid vira false, significando que o barco não foi destrido completamente.
		if (tab[x][y] == 1) valid = false;

		// Coloca o valor do barco para -1, definindo que ele já foi processado, testa as casas vizinhas ao barco.
		tab[x][y] = -1;
		dfs(tab, x+1, y, valid);
		dfs(tab, x-1, y, valid);
		dfs(tab, x, y+1, valid);
		dfs(tab, x, y-1, valid);
	}

}

int main() {
	int n, m;	
	vector<vector<int> > tab(MAXT, vector<int>(MAXT, -1));
	//Lê a quantidade de colunas e linhas do tabuleiro
	scanf("%d %d", &n, &m);
	//Lê e identifica os barcos no tabuleiro
	for (int i = 1; i <= n; ++i) {
		char c;
		scanf("%c", &c); //apenas para dar ignore no \n
		for (int j = 1; j <= m; ++j) {
			scanf("%c", &c);

			if (c == '#') tab[i][j] = 1;
		}
	}

	int plays;
	scanf("%d", &plays);
	for (int i = 0; i < plays; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		tab[x][y] += 1;
	}
	int destroyed = 0;	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (tab[i][j] == 2) {
				bool valid = true;
				dfs(tab, i, j, valid);

				if (valid) destroyed++;
			}
		}
	}
	printf("%d\n", destroyed);
}
