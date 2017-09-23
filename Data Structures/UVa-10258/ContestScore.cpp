#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <sstream>
#include <vector>


#define MAXT 110
#define MAXQ 10

using namespace std;

struct Team {
	int tNum;
	int solved;
	vector<int> penalty;
	vector<bool> solvedQ;
	int pTime;
	int submissions;

	Team() : tNum {-1}, solved{ 0}, penalty(10, 0), solvedQ(10, false), pTime{0}, submissions{0} {}
};

bool compara(const Team & x, const Team & y) {
	if (x.solved > y.solved) return true;
	if (x.solved < y.solved) return false;
	if (x.pTime < y.pTime) return true;
	if (x.pTime > y.pTime) return false;
	if (x.tNum < y.tNum) return true;
	return false;
}


int main() {
	
	int t;
	cin >> t;
	cin.ignore();
	cin.ignore();
	for (int i = 0; i<t; ++i) {
		Team comp[MAXT];
		set<int> participants;
		bool (*comp_pt)(const Team &, const Team &) = compara;
		set<Team, bool(*)(const Team &, const Team &)> sortedParticipants (comp_pt);
		int n, q, time;
		char type;
		string entrada; 
		while (getline(cin, entrada) && entrada != "") {
			istringstream iss(entrada);
			iss >> n >> q >> time >> type;
			participants.insert(n);
			if (type == 'I') {
				comp[n].penalty[q]++;
			} else if (type == 'C' && comp[n].solvedQ[q] == false) {
				comp[n].solvedQ[q] = true;
				comp[n].pTime += (time + comp[n].penalty[q] * 20);
				comp[n].solved++;
			}
		}
		for (set<int>::iterator it = participants.begin(); it != participants.end(); ++it) {
			int num = (*it);
			comp[num].tNum = num;
			sortedParticipants.insert(comp[num]);
			comp[num] = Team();
		}

		for (auto it = sortedParticipants.begin(); it != sortedParticipants.end(); ++it) {
			printf("%d %d %d\n", (*it).tNum, (*it).solved, (*it).pTime);
		}
		if (i != t-1) printf("\n");
		participants.clear();
		sortedParticipants.clear();
	}
}
