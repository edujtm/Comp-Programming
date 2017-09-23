#include <list>
#include <vector>
#include <iostream>
#include <set>
#include <string>

#define MAXT 12 

using namespace std;

int main() {

	vector<int> interval = {2, 2, 1, 2, 2, 2, 1};
	vector<string> names = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
	list<pair<int, set<int>> > tons(MAXT, make_pair(0, set<int>()));
	int index = 0;
	// Inicializa uma lista que possui todas as notas de cada tom
	for (auto it = tons.begin(); it != tons.end(); ++it){
		int acc = index++; 	// O acumulador começa na primeira nota do tom
		(*it).first = acc;
		for (int j = 0; j < 8; ++j) {
			(*it).second.insert(acc % 12);
			acc += interval[j];
		}
	}	
	// Codigo abaixo para teste dos tons musicais
	/*
	for (auto it = tons.begin(); it != tons.end(); ++it) {
		cout << names[(*it).first] << " | ";
		for (auto t = (*it).second.begin(); t != (*it).second.end(); ++t) {
				cout << names[(*t)] << " ";
		}
		cout << endl;	
	}
	*/
	// Aqui começa a solução da questão
	int n;
	cin >> n;
	for (int i = 0; i< n; ++i) {
		int nota;
		cin >> nota;
		nota = (nota - 1) % 12;
		for (auto it = tons.begin(); it != tons.end();) {
			if ((*it).second.find(nota) == (*it).second.end()) {
				tons.erase(it++);	//Tive que colocar assim para evitar falha de segmentação
			} else {
				++it;
			}
		}
	}
	if (tons.size() != 0) {
		int lesser = (*(tons.begin())).first;
		cout << names[lesser] << endl;
	} else {
		cout << "desafinado" << endl;
	}
}
