#include <cstdio>
#include <algorithm>
#include <iostream>

#define MAXC 300
#define MAXA 150


using namespace std;

int main() {

	int s, n = 1;
	while (scanf("%d", &s) != EOF) {
		int lpm = 10, lph = 0, lnap = 0;
		char app[MAXC], ignore;
		int laph = 10, lapm = 0;
		int saph, sapm, faph, fapm, nap;
		pair<pair<int, int>, pair<int, int> > stime[MAXA];

		for (int i = 0; i < s; ++i) {
			scanf("%d:%d %d:%d", &saph, &sapm, &faph, &fapm);
			cin.ignore(MAXC, '\n');
			stime[i].first = make_pair(saph, sapm);
			stime[i].second = make_pair(faph, fapm);
		}

		sort(stime, stime+s);
		
		for (int i = 0; i < s; ++i) {
			saph = stime[i].first.first;
			sapm = stime[i].first.second;
			faph = stime[i].second.first;
			fapm = stime[i].second.second;
			nap = sapm - lapm + 60 * (saph - laph);
			if (nap > lnap) {
				lnap = nap;
				lpm = lapm;
				lph = laph;
			}
			laph = faph;
			lapm = fapm;
		}
		nap = -lapm + 60 * (18 - laph);
		if (nap > lnap) {
			lnap = nap;
			lpm = lapm;
			lph = laph;
		}
		if (lnap / 60 == 0) {
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d minutes.\n", n++, lph, lpm, lnap);
		} else {
			int hours = lnap / 60;
			int minutes = lnap % 60;
			printf("Day #%d: the longest nap starts at %02d:%02d and will last for %d hours and %d minutes.\n", n++, lph, lpm, hours, minutes);
		}
	}
}
