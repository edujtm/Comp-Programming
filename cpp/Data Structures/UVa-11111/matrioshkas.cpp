#include <stack>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main() {

	string entrada;
	while(getline(cin, entrada)) {
		istringstream iss(entrada);
		int n;
		stack<int> size;
		stack<int> last;
		bool valid = true;
		while (iss >> n) {
			if (n < 0) {
				last.push(-n);
				size.push(0);
			} else if (n > 0) {
				if (last.size() > 0 && last.top() == n && size.top() < n) {
					size.pop();
					if (size.size() > 0) size.top() += n;
					last.pop();	
				} else {
					valid = false;
					break;
				}
			}
		}

		if (last.size() == 0 && valid) {
			cout << ":-) Matrioshka!\n";
		} else {
			cout << ":-( Try again.\n";
		}
	}
}
