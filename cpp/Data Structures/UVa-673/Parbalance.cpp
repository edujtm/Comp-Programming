#include<string>
#include<iostream>
#include<stack>

using namespace std;

int main() {

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		string entrada;
		getline(cin, entrada);
		stack<char> balance;
		bool valid = true;
		for (int j = 0; j<(int) entrada.size(); ++j) {
			if (entrada[j] == '(' || entrada[j] == '[') {
				balance.push(entrada[j]);
			} else if (entrada[j] == ')' || entrada[j] == ']') {
				if (balance.size() == 0 || (entrada[j] == ']' && balance.top() != '[') || (entrada[j] == ')' && balance.top() != '(')) {
					valid = false;
					break;
				} else {
					balance.pop();
				}
			}
		}

		if (valid && balance.size() == 0) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}
