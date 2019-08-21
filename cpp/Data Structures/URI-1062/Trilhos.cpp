#include <cstdio>

using namespace std;

#define MAXT 1000

int trains[MAXT];
int tam;

void pop() { if (tam > 0) tam--;}

void push(int t) { trains[tam++] = t;}

int top() { return trains[tam-1];}

void clear() {tam = 0;}

int main() {
	
	int n, ord, t = 0;
	bool valid = true;
	scanf("%d", &n);
	while ( n != 0 ) {
		scanf("%d", &ord);
		while (ord != 0) {
			for (int i = 1; i < n; ++i) {				
				if (ord > t) {
					while (ord != t) {
						push(++t);
					}
					pop();
				} else {
					if (top() != ord) { 
						valid = false;
					}
					pop();
				} 
				scanf("%d", &ord);	
			}
			if (valid) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			scanf("%d", &ord);
			clear();
			t = 0;
			valid = true;	
		}
		printf("\n");
		scanf("%d", &n);
	}
}
