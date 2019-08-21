// Essa questão eu fiquei orgulhoso, passei o dia todo sofrendo.
// Solved com orgulho
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXP 60

using namespace std;

char image[MAXP][MAXP];

void bfsdot(char arr[MAXP][MAXP], int x, int y) {
	arr[x][y] = '*';

	if (arr[x-1][y] == 'X') bfsdot(arr, x-1, y);
	if (arr[x+1][y] == 'X') bfsdot(arr, x+1, y);
	if (arr[x][y-1] == 'X') bfsdot(arr, x, y-1);
	if (arr[x][y+1] == 'X') bfsdot(arr, x, y+1);
}

// Remove os pontos do dado da imagem e conta a quantidade de um dado
void bfsdice(char arr[MAXP][MAXP], int x, int y, int & count) {
	char temp = arr[x][y];
	arr[x][y] = '.';

	if (temp == 'X') {
		count++;
		bfsdot(arr, x, y);
	}

	// Continua a apagar os locais adjacentes que representam o dado (i.e. arr[x][y] == '#')
	if (arr[x-1][y] != '.') bfsdice(arr, x-1, y, count);
	if (arr[x+1][y] != '.') bfsdice(arr, x+1, y, count);
	if (arr[x][y-1] != '.') bfsdice(arr, x, y-1, count);
	if (arr[x][y+1] != '.') bfsdice(arr, x, y+1, count);
}

int main() {

	int w, h;
	for (int i = 0; i < MAXP; ++i) {
		for (int j = 0; j < MAXP; ++j) {
			image[i][j] = '.';
		}
	}
	int throws = 1;
	while (scanf("%d %d", &w, &h) && (w != 0 || h != 0)) {
		vector<int> dices;
		char ignore;
		scanf("%c", &ignore);
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				char c;
				scanf("%c", &c);
				image[i][j] = c;
			}
			scanf("%c", &ignore);
		}


		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				int result = 0;
				if (image[i][j] != '.') bfsdice(image, i, j, result); 
				if (result != 0) dices.push_back(result);
			}
		}

		sort(dices.begin(), dices.end());

		printf("Throw %d\n", throws++);
		if (dices.size() > 0) printf("%d", dices[0]);
		for (int i = 1; i < (int) dices.size(); ++i) {
			printf(" %d", dices[i]);
		}
		printf("\n\n");
	}
}
