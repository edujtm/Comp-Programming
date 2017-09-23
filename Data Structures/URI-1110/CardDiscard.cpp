#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<int> fila;
	int n;
	while (cin >> n && n != 0) {
			for (int i = 1; i <= n; i++) fila.push(i);
			cout << "Discarded cards:";
			int aux = 0;
			while (fila.size() != 1) {
				if (aux == 0) cout << " " << fila.front();
				else cout << ", " << fila.front();
				fila.pop();
				fila.push(fila.front());
				fila.pop();
				++aux;
			}
		cout << endl;
		cout << "Remaining card: " << fila.front() << endl;
		fila.pop(); 
	}
}
