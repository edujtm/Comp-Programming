#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int main() {

	int serv, client;
	
	while (scanf("%d %d", &serv, &client) && serv != 0 && client != 0) {
		vector<set<string>> servers(serv);
		for (int i = 0; i < serv; ++i) {
			int qntApp;
			scanf("%d", &qntApp);
			for (int j = 0; j < qntApp; ++j) {
				string app;
				cin >> app;
				servers[i].insert(app);
			}
		}

		int connections = 0;
		vector<set<int>> connect(client);
		for (int i = 0; i < client; ++i) {
			int qntApp;
			scanf("%d", &qntApp);
			for (int j = 0; j < qntApp; ++j) {
				string app;
				cin >> app;
				for (int k = 0; k < serv; ++k) {
					if (servers[k].find(app) != servers[k].end()) {
						connect[i].insert(k);
					}
				}
			}
			connections += connect[i].size();
		}
		printf("%d\n", connections);
	}
}
