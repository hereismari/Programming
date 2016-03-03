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

        if(n == 0) break;

        vector<int> v;
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            v.pb(x);
        }
    
        sort(v.begin(), v.end());

        do {
          printf("%d", v[0]);
          for(int i = 1; i < n; i++) printf(" %d", v[i]);
          printf("\n");
        } while (next_permutation(v.begin(), v.end()));
        printf("\n");
    }

	return 0; 
}
