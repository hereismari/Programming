#include <bits/stdc++.h> 

using namespace std; 

#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

#define MAX 1000100  
#define INF 1000000000

int n, m, x, y;

int main() {
 
    while(scanf("%d %d", &n, &m) != EOF) {

        map<int,int> aux;

        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            aux[x]++;
        }

        ll s = 0;
        vector<int> ans;
        for(int i = 1; i <= 1000000000; i++) {
            if(s + i <= m && aux.find(i) == aux.end()) {
                ans.pb(i);
                s += i;
            }
            if(s + i > m) break;
        }

        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); i++)
            printf("%d ", ans[i]);
    }

	return 0; 
}
