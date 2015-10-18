#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll long long
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

ll n, m, x, y, a[3];
map<ll, int> ans;
bool poss;

void dp() {
    
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 1; k <= m; k++) {
                ll value = a[0] * i + a[1] * j + a[2] * k;
                if(ans.find(value) == ans.end()) ans[value] = 1;
                else ans[value]++;
            }
}

int main() {
 
    while(scanf("%lld %lld", &n ,&m) != EOF) {
        a[0] = a[1] = a[2] = 0LL;
        poss = true;
        for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
        ans.clear();
        dp();
        for(map<ll, int>::iterator it = ans.begin(); it != ans.end(); it++)
            if(it->second >= 2) { poss = false; break;}
        
        if(poss) cout << "Lucky Denis!" << endl;
        else cout << "Try again later, Denis..." << endl;
    }

	return 0; 
}
