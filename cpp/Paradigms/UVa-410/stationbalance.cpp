#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAXC 10
#define MAXW 1010

using namespace std;

int main() {

	int c, s, set = 1;
	while (scanf("%d %d", &c, &s) != EOF) {
		int specimens[MAXC];
		vector<vector<int> > chamb(MAXC, vector<int>());
		double cntchamb[MAXC];
		double med = 0.0;
		for (int i = 0; i < s; ++i) {
			int mass;
			scanf("%d", &mass);
			specimens[i] = mass;
			med += mass;
		}
		
		for (int i = 0; i < c; ++i) cntchamb[i] = 0.0;

		med /= c;
		sort(specimens, specimens+s);

		for (int i = s-1, j = 0, k = 1; i >= 0; --i, j += k) {
			cntchamb[j] += specimens[i];
			chamb[j].push_back(specimens[i]);
			if (j == c-1 && k == 1) k = 0;
			else if (j == c - 1 && k == 0) k = -1;
		}

		double imbalance = 0.0; 
		printf("Set #%d\n", set++);
		for (int i = 0; i < c; ++i) {
			imbalance += fabs(cntchamb[i] - med);
			printf(" %d:", i);
			for (int j = 0; j < chamb[i].size(); ++j) {
				printf(" %d", chamb[i][j]);
			}
			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n\n", imbalance);
	}
}
