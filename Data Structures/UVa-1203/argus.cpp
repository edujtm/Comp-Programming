#include <iostream>
#include <string>
#include <queue>

#define MAXR 3000

using namespace std;
struct classcomp {
	bool reverse;
	public:
	classcomp(const bool & isReverse = true) : reverse{ isReverse} {}

	bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const 
		{
			if (reverse) return lhs>rhs;
			else return lhs < rhs;
		}
};

int main() {
	int periods[MAXR];
	string reg;
	priority_queue<pair<int, int>,vector<pair<int, int> >, classcomp> order; // o vector e o functor são para inverter a ordem do priority queue
	while (cin >> reg && reg[0] == 'R' ) {
		int r, period;
		cin >> r >> period;
		cin.ignore();
		order.push(make_pair(period, r));
	    	periods[r] = period;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {	
		pair<int, int> value = order.top();
		order.pop();
		cout << value.second << endl;
		order.push(make_pair(value.first + periods[value.second], value.second));
	}	
	return 0;
}
