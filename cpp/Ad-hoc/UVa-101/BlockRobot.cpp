#include <iostream>
#include <string>
#include <vector>

#define MAXP 30

using namespace std;

//Retira todos os objetos na pilha p[current] que estão em cima de n
void removeAllFromTop(vector<vector<int> > & p, int current, int n) {
	while (p[current].back() != n) {
		p[p[current].back()].push_back(p[current].back());
		p[current].pop_back();
	}
} 

//Assume que não há nada em cima de a e b
void moveAtoB(vector<vector<int> > & p, int currenta, int currentb) {
	p[currentb].push_back(p[currenta].back());
	p[currenta].pop_back();
}

void pileAtoB(vector<vector<int> > & p, int currenta, int currentb, int a) {
	vector<int> aux;
	while (p[currenta].back() != a) {
		aux.push_back(p[currenta].back());
		p[currenta].pop_back();
	}
	moveAtoB(p, currenta, currentb);
	while (aux.size() > 0) {
		p[currentb].push_back(aux.back());
		aux.pop_back();
	}
}

int main() {

	int n;
	cin >> n;
	vector<vector<int> > pilhas(MAXP, vector<int>());

	for (int i = 0; i < n; ++i) pilhas[i].push_back(i);

	string m1, m2;
	 int a, b;	
	cin >> m1;
	while (m1[0] != 'q') {

		cin >> a >> m2 >> b;
		if (a != b) {
			int currenta, currentb;
			//Busca todas as pilhas por a e b. Infelizmente nao posso usar break porque estou buscando por a e b em um unico loop
			//é uma especie de contains() nas pilhas
			for (int i = 0; i<n; ++i) {
				for (int j = 0; j<pilhas[i].size(); ++j) {
					if (pilhas[i][j] == a) {
						currenta = i;
					}
					if(pilhas[i][j] == b) {
						currentb = i;
					}
				}
			}
			if (currenta != currentb) {
				//move a onto b
				if (m1[0] == 'm' && m2[1] == 'n') {

					removeAllFromTop(pilhas, currentb, b);
					removeAllFromTop(pilhas, currenta, a);
					moveAtoB(pilhas, currenta, currentb);

				} else if (m1[0] == 'm' && m2[1] == 'v') {	//move a over b

					removeAllFromTop(pilhas, currenta, a);
					moveAtoB(pilhas, currenta, currentb);

				} else if (m1[0] == 'p' && m2[1] == 'n') {	//pile a onto b

					removeAllFromTop(pilhas, currentb, b);
					pileAtoB(pilhas, currenta, currentb, a);
	
				} else if (m1[0] == 'p' && m2[1] == 'v') { //pile a over b
					pileAtoB(pilhas, currenta, currentb, a);
				}
			}
		}
		cin >> m1;
	}

	for (int i = 0; i < n; ++i) {
		cout << i << ":";
		if (pilhas[i].size() == 0) {
			cout << endl;
		} else {
			for (int j = 0; j< pilhas[i].size(); ++j) {
				cout << " " << pilhas[i][j];
			}
			cout << endl;
		}
	}
}
