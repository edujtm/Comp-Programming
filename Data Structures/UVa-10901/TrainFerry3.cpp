#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#define MAXC 10000

using namespace std;

struct Ferry {
	int capacity;
	string side;
};

struct Carro {
	int ta;
	string side;
};

int tc[MAXC];

int main() {
	
	queue<Carro> fila;
	string side;
	int c;
	Ferry theFerry;
	scanf("%d", &c);
	for (int i=0; i<c; i++) {
		int time = 0, n, t, m;
		Carro arrived;
		scanf("%d %d %d", &n, &t, &m);
		theFerry.capacity = n;
		theFerry.side = "left";

		for (int i = 0; i < m; i++) {
			cin >> arrived.ta >> arrived.side;
			fila.push(arrived);
		}

		while (fila.size() != 0) {
			if (fila.front().side == theFerry.side) {
				int j = 0;
				if (time < fila.front().ta) time = fila.front().ta;
				while ( j < n && fila.front().ta <= time && fila.front().side == theFerry.side) {
					cout << time + t << endl;
					j++;
					fila.pop();
				}
				time += t;
				if (theFerry.side == "left") {
					 theFerry.side = "right";
				} else {
					theFerry.side = "left";
				} 
			} else {
				if (time < fila.front().ta) time = fila.front().ta;
				time += t;
				if (theFerry.side == "left") {
					 theFerry.side = "right";
				} else {
					theFerry.side = "left";
				}	 
			}
		}
		cout << endl;
	}
}
