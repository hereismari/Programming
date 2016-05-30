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

vector<int> v;

int main() {
	
    int n, m, d;
	char c;
	int x;

	scanf("%d", &n);

    for(int turn = 1; turn <= n; turn++) {
    	
    	scanf("%d %d", &m, &d);
    	
        v.clear();
        
        v.pb(0);
        
        for(int i = 0; i < m; i++) {
            scanf("\n%c-%d", &c, &x);
            v.pb(x);
            if(c == 'B') v.pb(x);
        }       
       
        v.pb(d);
        
        int ans = 0;
        for(int i = 3; i < v.size(); i += 2)
            ans = max(ans, v[i]-v[i-2]);

        for(int i = 2; i < v.size(); i += 2)
            ans = max(ans, v[i]-v[i-2]);
        
        printf("Case %d: %d\n", turn, ans);
    }
    
}
