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
 
    while(scanf("%d",&n) != EOF) {

        int a[n], b[n], c[n];
        for(int i = 0; i < n-1; i++) scanf("%d", &a[i]);
        for(int i = 0; i < n-1; i++) scanf("%d", &b[i]);
        for(int i = 0; i < n; i++) scanf("%d", &c[i]);

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int aux = c[i];
            for(int j = 0; j < min(i, n-1); j++) aux += a[j];
            for(int j = i; j < n-1; j++) aux += b[j];
            ans.pb(aux);
        }
    
        sort(ans.begin(), ans.end());
        printf("%d\n", ans[0] + ans[1]);

    }

	return 0; 
}
