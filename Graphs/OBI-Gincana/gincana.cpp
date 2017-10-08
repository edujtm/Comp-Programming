#include <cstdio>
#include <vector>

#define MAXG 1010

using namespace std;

vector<int> grupos[MAXG];
int alunos[MAXG];

void dfs(int x) {

	for (int i = 0; i < (int) grupos[x].size(); ++i) {
		int v = grupos[x][i];

		if (alunos[v] == -1) {
			alunos[v] = 1;
			dfs(v);
		}
	}

}

int main() {

	int qaluno, n;	

	scanf("%d %d", &qaluno, &n);
	
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);

		grupos[a-1].push_back(b-1);
		grupos[b-1].push_back(a-1);
	}

	for (int i = 0; i < qaluno; ++i) alunos[i] = -1;
	int qntGrupos = 0;
	for (int i = 0; i < qaluno ; ++i) {
		if (alunos[i] == -1) {

			qntGrupos++;
			alunos[i] = 1;
			dfs(i);
		}
	}

	printf("%d\n", qntGrupos);
}
