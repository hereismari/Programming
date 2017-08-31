#include <bits/stdc++.h>

#define MAX 1002
#define F first

using namespace std;

string s;
map<string, int> vis;

void solve(string aux) {
	
    if (vis[aux] == 0) {
    	
        vis[aux] = true;
        for (int i = 0; i < aux.length(); i++) {
            string new_aux = aux.substr(0, i) + aux.substr(i + 1, string::npos);
            if (!new_aux.empty()) {
                solve(new_aux);
            }
        }
    }
}

int main() {
	
    while (cin >> s) {
    	
        vis.clear();
        solve(s);

        for (map<string, int>::iterator it = vis.begin(); it != vis.end(); it++) cout << (*it).F << endl;
       
        cout << endl;
    }

    return 0;
}
