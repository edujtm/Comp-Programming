#include <cstdio>
#include <string>
#include <iostream>

#define MAXP 1000

using namespace std;

struct Stack {
	int tam = 0;
	char content[MAXP];

	void push(char x) {
		content[tam++] = x;
	}

	void pop() {
		if (tam > 0) tam--;
	}

	char front() {
		return content[tam-1];
	}

	void clear() {
		tam = 0;
	}
};

int main() {
	string entrada;
	while (getline(cin, entrada)) {
		Stack parentheses;
		bool valid = true;
		for (int i = 0; i<entrada.size(); i++) {
			if (entrada[i] == '(') {
				parentheses.push(entrada[i]);
			} else if (entrada[i] == ')') {
				if (parentheses.tam == 0 || parentheses.front() != '(') {
					valid = false;
					break;
				} else {
					parentheses.pop();
				}
			}
		}
		
		if (parentheses.tam != 0) valid = false;
		
		if (valid) cout << "correct\n";
		else cout << "incorrect\n";
	}
}
