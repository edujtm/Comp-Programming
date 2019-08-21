#include <cstdio>
#include <cmath>

#define MAXN 100100

using namespace std;

int main() {

	int n;
	while(scanf("%d", &n) && n != 0) {
		long long acc = 0;
		unsigned long long result = 0;

		for (int i = 0; i < n; ++i) {
			int value;
			scanf("%d", &value);
			acc += value;
			// printf("%lld ", acc);
			if (i != n-1) result += abs(acc);
		}
		//printf("\n");
		printf("%llu\n", result);
		
	}
}
