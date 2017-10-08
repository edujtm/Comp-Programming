#include <cstdio>

#define MAXS 100100

using namespace std;

int main() {
	
	int s, b;
	int right[MAXS], left[MAXS];
	while(scanf("%d %d", &s, &b) && s != 0 && b != 0) {

		for (int i = 1; i<=s; ++i) {
			right[i] = i+1;
			left[i] = i-1;
		}
	
		for (int i = 0; i<b; ++i) {
			int l, r;
			scanf("%d %d", &l, &r);
			right[left[l]] = right[r];
			left[right[r]] = left[l]; 

			if (left[right[r]] != 0) {
				printf("%d ", left[right[r]]);
			} else {
				printf("* ");
			} 
			if (right[left[l]] != s+1) {
				printf("%d\n", right[left[l]]);
			} else {
				printf("*\n");
			}	
		}
		printf("-\n");
	}
}
