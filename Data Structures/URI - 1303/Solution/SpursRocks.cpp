//Unsolved - Wrong Answer
#include <iostream>
#include <algorithm>

#define MAXW 110

using namespace std;

int pont[MAXW];
double cAvg[MAXW];
int score[MAXW][2];

bool compara(int p1, int p2) {
	if (pont[p1-1] > pont[p2-1]) return true;
	if (pont[p1-1] < pont[p2-1]) return false;
	if (cAvg[p1-1] > cAvg[p2-1]) return true;
	if (cAvg[p1-1] < cAvg[p2-1]) return false;
	if(score[p1-1][0] > score[p2-1][0] ) return true;
	if(score[p1-1][0] < score[p2-1][0]) return false;
	if (p1 > p2) return true;
	if (p1 < p2) return false;
	return false;
}

int main() {
	int n, inst = 1;
    int times[MAXW];
	
	cin >> n;

	do {
		int x, y, w, z;
		for (int i = 0; i < n; ++i) {
			times[i] = i + 1;
			pont[i] = 0;
			cAvg[i] = 0;
			score[i][0] = 0;
			score[i][1] = 1;
		}

		for (int i = 0; i < (n * (n - 1))/2 ; i++) {
			scanf("%d %d %d %d", &x, &y, &w, &z);
			x--;
			w--;
			if ( y > z) {
				pont[x] += 2;
				pont[w]++;
			} else {
				pont[w] += 2;
				pont[x]++;
			} 
			score[x][0] += y;
			score[x][1] += z;
			score[w][0] += z;
			score[w][1] += y;
			if (score[x][1] != 0 && score[w][1] != 0) {
				cAvg[x] = (double) score[x][0] / score[x][1];
				cAvg[w] = (double) score[w][0] / score[w][1];
			} else if (cAvg[x] == 0) {
				cAvg[x] = score[x][0];
			} else {
				cAvg[w] = score[w][0];
			}
		}

		sort(times, times+n, compara);

		cout << "Instancia " << inst << endl;

		cout << times[0];
		for (int i = 1; i < n; i++) {
			cout << " " << times[i];
		}
		cout << endl << endl;

		inst++;
		cin >> n;

	} while (n != 0);

}
