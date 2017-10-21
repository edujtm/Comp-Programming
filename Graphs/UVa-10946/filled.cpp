#include <cstdio>
#include <set>

#define MAXL 60

using namespace std;

struct classcomp {
	bool operator() (const pair<int, char> & lhs, const pair<int, char> & rhs) const {
		if (lhs.first > rhs.first) return true;
		if (lhs.first < rhs.first) return false;
		if (lhs.second < rhs.second) return true;
		if (lhs.second > rhs.second) return false;
		return true;
	}
};

char island[MAXL][MAXL];

void bfs(char arr[MAXL][MAXL], pair<int, char> & hole, int x, int y) {
	char temp = arr[x][y];
	arr[x][y] = '.';
	hole.first += 1;
	if (arr[x-1][y] == temp) bfs(arr, hole, x-1, y);
	if (arr[x+1][y] == temp) bfs(arr, hole, x+1, y);
	if (arr[x][y+1] == temp) bfs(arr, hole, x, y+1);
	if (arr[x][y-1] == temp) bfs(arr, hole, x, y-1);
}

int main() {

	int x, y;
	for (int i = 0; i < MAXL; ++i) {
		for (int j = 0; j < MAXL; ++j) {
			island[i][j] = '.';
		}
	}

	int count = 1;
	while (scanf("%d %d", &x, &y) && x != 0 && y != 0) {
		char ignore;
		scanf("%c", &ignore); // Retira o newline após os numeros
		multiset<pair<int, char>, classcomp > holes;
		// Lê os valores do mapa de buracos
		for (int i = 1; i <= x; ++i) {
			for (int j = 1; j <= y; ++j) {
				char c; 
				scanf("%c", &c);
				island[i][j] = c; 
			}
			scanf("%c", &ignore); // Retira o newline ao final de cada linha
		}

		for (int i = 1; i <= x; ++i) {
			for (int j = 1; j <= y; ++j) {
				if (island[i][j] != '.') {
					auto mp	 = make_pair(0 , island[i][j]);
					bfs(island, mp, i, j);
					holes.insert(mp);
				}
			}
		}
		printf("Problem %d:\n", count++);
		for (auto it = holes.begin(); it != holes.end(); ++it) {
			printf("%c %d\n", (*it).second, (*it).first);
		}
	}
}
