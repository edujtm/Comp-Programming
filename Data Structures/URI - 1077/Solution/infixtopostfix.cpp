#include <cstdio>
#include <string>
#include <iostream>

#define MAXO 500

using namespace std;

struct Stack {

	int tam = 0;
	char contents[MAXO];

	void push(char x) {
		contents[tam++] = x;
	} 

	char front() {
		return contents[tam-1];
	}

	void pop() {
		if (tam > 0) tam--;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	cin.ignore();
	for(int i = 0; i < n; i++) {
		Stack operators;
		string expression;
		char op;
		getline(cin, expression);

		for (int i = 0; i<expression.size(); i++) {
			op = expression[i];
			if ((op >= '0' && op <= '9') || (op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z')) {
				cout << op;
			} else if (op == '+' || op == '-') {
				while (operators.tam > 0 && operators.front() != '(') {
					cout << operators.front();
					operators.pop();
				}
				operators.push(op);
			} else if (op == '/' || op == '*') {
				while (operators.tam > 0 && operators.front() != '+' && operators.front() != '-' && operators.front() != '(') {
					cout << operators.front();
					operators.pop();
				}
				operators.push(op);
			} else if (op == '^') {
				operators.push(op);
			} else if (op == ')') {
				while (operators.tam > 0 && operators.front() != '(' ) {
					cout << operators.front();
					operators.pop();
				}
				operators.pop();
			} else if (op == '(') {
				operators.push(op);
			}	
		}

		while (operators.tam > 0) {
			cout << operators.front(); 
			operators.pop();
		}
		printf("\n");
	}
}
