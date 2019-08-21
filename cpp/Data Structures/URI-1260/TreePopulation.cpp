#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main() {
	
	int n;
	map<string, double> arvores;
	scanf("%d", &n);
	cin.ignore();
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string entrada;
		int pop = 0;
		while (getline(cin, entrada)) {
			if (entrada == "") break;
			if (arvores.find(entrada) != arvores.end()) arvores[entrada]++;
			else arvores[entrada] = 1.0;
			pop++;
		}
		map<string, double>::iterator it;
		for (it = arvores.begin(); it != arvores.end(); it++) {
			cout << (*it).first;
			printf(" %.4lf\n", ((*it).second/pop) * 100);
		}
		if (i != n-1) cout << endl;
		arvores.clear();
	} 
}
