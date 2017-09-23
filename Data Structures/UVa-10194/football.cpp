#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define MAXT 35

using namespace std;
struct team {
    string name;
    string lname;
    int wins;
    int points;
    int goaldiff;
    int goals;
    int games;
    int losses;
};

bool compara (const team & rhs, const team & lhs ) {
        if (rhs.points > lhs.points) return true;
        if (rhs.points < lhs.points) return false;
        if (rhs.wins > lhs.wins) return true;
        if (rhs.wins < lhs.wins) return false;
        if (rhs.goaldiff > lhs.goaldiff) return true;
        if (rhs.goaldiff < lhs.goaldiff) return false;
        if (rhs.goals > lhs.goals) return true;
        if (rhs.goals < lhs.goals) return false;
        if (rhs.games < lhs.games) return true;
        if (rhs.games > lhs.games) return false;
        if (rhs.lname.compare(lhs.lname) == -1) return true;
        if (rhs.lname.compare(lhs.lname) == 1) return false;
        return false;
}


int main() {
    int t;
    cin >> t;
    cin.ignore();
    string tourn;
    for (int i = 0; i < t; ++i) {
        getline(cin, tourn);
        int nteams;
        cin >> nteams;
        cin.ignore();
        map<string, team> teams;
        vector<team> order;
        for (int j = 0; j<nteams; ++j) {
            string teamname;
            getline(cin, teamname, '\n');
            teams[teamname] = team();
            teams[teamname].name = teamname;
            teams[teamname].lname = teamname;
            for (int l = 0; l < teamname.size(); l++) {
                if (teamname[l] >= 'A' && teamname[l] <= 'Z') teams[teamname].lname[l] = teamname[l] + 32;
            }
        }        
		int g;
        cin >> g;
        cin.ignore();
        for (int j = 0; j < g; ++j) {
            string name1, name2;
            int g1, g2;
            getline(cin, name1, '#');
            cin >> g1;
            cin.ignore();
            cin >> g2;
            cin.ignore();
            getline(cin, name2);
            teams[name1].goals += g1;
            teams[name2].goals += g2;
            teams[name1].goaldiff += g1 - g2;
            teams[name2].goaldiff += g2 - g1;
            teams[name1].games++;
            teams[name2].games++;
            if (g1 > g2) {
                teams[name1].wins += 1;
                teams[name2].losses += 1;
                teams[name1].points += 3;
            } else if (g2 > g1) {
                teams[name2].wins += 1;
                teams[name1].losses += 1;
                teams[name2].points += 3;
            } else {
                teams[name1].points += 1;
                teams[name2].points += 1;
            }
        }
            for (auto it = teams.begin(); it != teams.end(); it++) {
                order.push_back(it->second);
            }
	    sort(order.begin(), order.end(), compara);
            cout << tourn << endl;
            int z = 1;
            for (auto it = order.begin(); it != order.end(); it++) {
                cout << z << ") " << (*it).name << " " << (*it).points << "p, " << (*it).games << "g (" << (*it).wins << "-" << (*it).games - ((*it).wins + (*it).losses) << "-" << (*it).losses << "), " << (*it).goaldiff << "gd (" << (*it).goals << "-" << (*it).goals + ((*it).goaldiff > 0 ? -(*it).goaldiff : -((*it).goaldiff)) << ")" << endl;
            z++;
            }
            if (i != t-1) cout << endl;
	    teams.clear();
        }

    }


