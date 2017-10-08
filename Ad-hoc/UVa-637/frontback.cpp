#include <iostream>

using namespace std;

int main() {
	int n;
	while(cin >> n && n != 0) {
		int k = 4 * (((int) (n+3)/4));
		int j = k - n;
		int aux = n, ini = 1, fim = n;
		cout << "Printing order for " << n << " pages:" << endl;
		while (ini <= fim) {
			if ((ini-1)%2 == 0) {
				cout << "Sheet " << (int) (ini-1)/2 + 1 << ", front: "; 
					if (j > 0) {
						cout <<  "Blank";
					} else {
						cout << fim;
					}	
				       
				cout << ", " << ini;
				cout << endl;
				if (j > 0) {
					j--;
				} else {
					fim--;
				}
			} else {
				cout << "Sheet " << (int) (ini-1)/2 + 1 << ", back : " << (ini-1)+1 << ", ";
					if (j > 0) {
					       cout << "Blank"; 
					} else {
						cout << fim; 
					}
					cout << endl;
				if (j > 0) {
					j--;
				} else {
					fim--;
				}
			}
			ini++;
		}
	}
}
