#include <cstdio>
#include <vector>

using namespace std;

bool checkUpperLeft(int table[10][10], int x, int y) {
	if (x-1 == 0 || y-1 == 0) return true;
	
	if (table[x-1][y-1] == 1) return false;

	return checkUpperLeft(table, x-1, y-1);
}

bool checkLowerLeft(int table[10][10], int x, int y) {
	if (x-1 == 0 || y+1 == 9) return true;
	
	if (table[x-1][y+1] == 1) return false;

	return checkLowerLeft(table, x-1, y+1);
}

bool checkUpperRight(int table[10][10], int x, int y) {
	if (x+1 == 9 || y-1 == 0) return true;
	
	if (table[x+1][y-1] == 1) return false;

	return checkUpperRight(table, x+1, y-1);
}

bool checkLowerRight(int table[10][10], int x, int y) {
	if (x+1 == 9 || y+1 == 9) return true;
	
	if (table[x+1][y+1] == 1) return false;

	return checkLowerRight(table, x+1, y+1);
}

bool checkLeftRight(int table[10][10], int x, int y) {
	for (int i = 1; i < 9; ++i) {
		if (i != y && table[x][i] == 1)	return false;
	}
	return true;
}

bool isSafe(int table[10][10], int x, int y) {
	return checkUpperLeft(table, x, y) && checkLowerLeft(table, x, y) && checkUpperRight(table, x, y) && checkLowerRight(table, x, y) && checkLeftRight(table, x, y);
}

void backtracking(int table[10][10], vector<vector<int> > & solutions, int newpos[], int col) {
	if (col == 9) {
		for (int i = 1; i < 9; ++i) {
			solutions[i].push_back(newpos[i]);
		}
		return;
	}

	for (int i = 1; i < 9; ++i) {
		if (isSafe(table, i, col)) {
			table[i][col] = 1;
			newpos[i] = col;

			backtracking(table, solutions, newpos, col+1);

			table[i][col] = 0;
		}
	}

	// Apos processar todas as possibilidades dessa rainha, retorna para a rainha anterior
	return;
}

void solveNQueens(int table[10][10], vector<vector<int> > & solutions) {
	int col = 1;
	int newpos[10];
	backtracking(table, solutions, newpos, col);
}

int main() {

	int table[10][10];
	int initpos[10];
	int firstpos, tcase = 1;

	vector<vector<int> > solutions(10, vector<int>());

	// Acha todas as soluções possiveis e guarda as posicoes verticais das rainhas em cada solucao na matriz solutions
	solveNQueens(table, solutions);

	while (scanf("%d", &firstpos) != EOF) {
		initpos[1] = firstpos;
		for (int i = 2; i < 9; ++i) {
			int vpos;
			scanf("%d", &vpos);
			initpos[i] = vpos;
		}
		int moveCount = 0;
		
		// Itera pelas linhas de solutions
		for (int i = 0; i < solutions[1].size(); ++i) {

			int countDiff = 0;
			// Calcula a quantidade de movimentos
			for (int j = 1; j < 9; ++j) {
				countDiff += solutions[j][i] != initpos[j]  ? 1 : 0;
			}

			if (i == 0) {
				moveCount = countDiff;
			} else {
				//Encontra a menor quantidade de movimentos
				if (countDiff < moveCount) {
					moveCount = countDiff;
				}
			}
		}

		printf("Case %d: %d\n", tcase++, moveCount);
		
	}
}

