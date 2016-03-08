#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll long long int
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
 
    while(true) {

        scanf("%d %d", &n, &m);
        if(n == 0 &&  m == 0) break;
        
        int a[n];
        multiset<int> st;

        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < m; i++) { scanf("%d", &x); st.insert(x); }
    
        if(m < n) { printf("Loowater is doomed!\n"); continue; }

        ll ans = 0;
        bool can = true;
        for(int i = 0; i < n; i++) { 
            multiset<int>::iterator j = st.lower_bound(a[i]);
            if(j == st.end()) { can = false; break; }
            ans += *j;
            st.erase(j);
        }

        if(can) printf("%lld\n", ans);
        else puts("Loowater is doomed!");

    }

	return 0; 
}
