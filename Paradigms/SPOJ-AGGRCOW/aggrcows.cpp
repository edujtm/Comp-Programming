#include <cstdio>
#include <algorithm>

#define MAXS 100010

using namespace std;

int buscab(int stalls[], int n, int c) {
	int low = stalls[1] - stalls[0];
	int high = stalls[n-1] - stalls[0];

	if (c == 2) return high;
	
	for (int i = 1; i < n; ++i) {
		int diff = stalls[i] - stalls[i-1];
		if (diff < low) low = diff;
	}

	int result = high;

	while (low <= high) {
		int mid = low + (high - low + 1) / 2;
		int cows = 1, atual = stalls[0];
		 //printf(" -- %d --\n", mid);
		//printf("%d\n", atual);
		for (int i = 1; i < n; ++i) {
			int diff = stalls[i] - atual;
			if (diff >= mid) {
				atual = stalls[i];
				//printf("%d\n", atual);
				cows++;
			}
		}

		if (cows >= c) {
			result = mid;
			low = mid+1;
		} else {
			high = mid-1;
		}
	}

	return result;
}

int main() {

	int t;
	scanf("%d", &t);
	while(t--) {
		int stalls[MAXS];
		int n, c;
		scanf("%d %d", &n, &c);

		for (int i = 0; i < n; ++i) scanf("%d", &stalls[i]);

		sort(stalls, stalls+n);

		int result = buscab(stalls, n, c);

		printf("%d\n", result);

	}
	return 0;
}
