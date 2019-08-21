#include <iostream>
#include <string>

#define MAXC 1000

using namespace std;

struct Stack {
	int tam = 0;
	char content[MAXC];

	void push(char x) {
		content[tam++] = x;
	}

	void pop() {
		if (tam > 0) tam--;
	}

	int front() {
		return content[tam-1];
	}

	void clear() {
		tam = 0;
	}
};

int main() {
	
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string entrada;
		Stack diamonds;
		int cnt = 0;
		getline(cin, entrada);
		for (int j = 0; j < entrada.size(); j++) {
			if (entrada[j] == '<') {
				diamonds.push(entrada[j]);
			} else if (entrada[j] == '>') {
				if (diamonds.tam > 0 && diamonds.front() == '<') {
					cnt++;
					diamonds.pop();
				}
			}
		}
		cout << cnt << endl;
		diamonds.clear();
	}
}
