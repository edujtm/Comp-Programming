#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

#define MAXW 50

int position[MAXW];
std::vector<std::string> words(MAXW, "");	

bool compara(int x, int y) {

	if (words[x].size() > words[y].size()) return true;
	else if (words[x].size() == words[y].size() && x <= y) return true;

	return false;
}

int main() {
	std::string entrada;
	int n;
	std::cin >> n;
	std::cin.ignore();

	for (int i = 0; i < n; i++) {
		int j = 0;

		std::getline(std::cin, entrada);

		for (int a = 0; a < entrada.size(); a++) {
			if (entrada.at(a) != ' ') {
				words[j].push_back(entrada.at(a));
			} else {
				j++;
			}
		}
		
		for (int a = 0; a <= j; a++) {
			position[a] = a;
		}

		std::sort(position, position+j+1, compara);

		std::cout << words[position[0]];
		words[position[0]] = "";
		for (int a = 1; a <= j; a++) {
			std::cout << " " << words[position[a]];
			words[position[a]] = "";
		}		

		std::cout << std::endl;
	}

}
