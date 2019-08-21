#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, l, c;
	
	while (scanf("%d %d %d", &n, &l, &c) != EOF ) {
		cin.ignore();
		string palavra;
		int linha = 1, caracter = 0, pag = 1;
		for (int i = 0; i < n; i++) {	//Entra com as palavras e conta os caracteres
			cin >> palavra;
			caracter += palavra.size();
			if (caracter > c) {
				linha++;
				caracter = 0;
				if (linha > l) {
					linha = 1;
					pag++;					
				}
				caracter += palavra.size();
			}
			if (i != n-1) caracter++;
		}
		printf("%d\n", pag);
	}
}
