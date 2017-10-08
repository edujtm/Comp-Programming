#include <cstdio>
#include <set>
#include <vector>

#define MAXP 10001
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
		
	for (int i = 0; i < t; ++i) {
		int solved[MAXP] = {0};
		set<int> qnt[3]; 
		set<int> solver[3];
		for (int j = 0; j < 3; ++j) {
			int n;
			scanf("%d", &n);
			for (int k = 0;k < n; ++k) {
				int problem;
				scanf("%d", &problem);
				if (solver[j].find(problem) == solver[j].end()) {
					solver[j].insert(problem);
					solved[problem]++;
				}	
			}
		}
		for (int j = 0; j < 3; j++) {
			for (auto it = solver[j].begin(); it != solver[j].end(); it++) {
				if (solved[*it] == 1) {
					qnt[j].insert(*it);
				}
			}
		}	
		int maxsolved = 0;
		for (int j = 0; j < 3; ++j) {
			if (qnt[j].size() > maxsolved){
				maxsolved  = qnt[j].size();
			}
		}
		printf("Case #%d:\n", i+1);
		for (int j = 0; j < 3; ++j) {
			if (qnt[j].size() == maxsolved) {
				printf("%d %d", j+1, maxsolved);
				for (auto it = qnt[j].begin(); it != qnt[j].end(); ++it) {
					printf(" %d", *it);
				}
				printf("\n");
			}
		}

	}

}
