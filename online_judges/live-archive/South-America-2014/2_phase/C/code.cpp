#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll unsigned long long
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y;
int main() {
 
    string s;
    while(cin >> s) {

    ll ans = 0, acum[3];
    int v = 0;
    acum[0] = 1; acum[1] = 0; acum[2] = 0;
    for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            v = (v + s[i] - '0') % 3;
            ans += acum[v]++; 
        }
        else {v = 0; acum[1] = acum[2] = 0; acum[0] = 1;}
    }

	cout << ans << endl;
    }
    return 0; 
}
