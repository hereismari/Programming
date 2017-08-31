#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

struct player {
    
    string name;
    int pontuation;
    
    player(string name = "", int pontuation=0) {
        this->name = name;
        this->pontuation = pontuation;
    }

    bool operator < (const player &o) const {
        return pontuation > o.pontuation;
    }
};

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    
    player p[n]; 
    vector<player> team[n];

    for(int i = 0; i < n; i++) {
        string name;
        int t, pont;
        cin >> name >> t >> pont;
        t--;
        team[t].pb(player(name,pont));
    }

    for(int i = 0; i < m; i++) sort(team[i].begin(), team[i].end());
    

    for(int i = 0; i < m; i++) {
	if(team[i].size() >= 3) {
           if(team[i][1].pontuation == team[i][2].pontuation) cout << "?" << endl;  
	   else  cout << team[i][0].name << ' ' << team[i][1].name << endl;        
	}
        else cout << team[i][0].name << ' ' << team[i][1].name << endl;
    }

    return 0;
}
