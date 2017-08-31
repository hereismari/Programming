#include <bits/stdc++.h> 

#define MAX 1000100 
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
 
using namespace std; 

int n, m, x, y;

int main() {
 
    while(scanf("%d",&n) != EOF){
        char c[n][n];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("\n%c", &c[i][j]);

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            int counter = 0;
            for(int j = 0; j < n; j++)
                counter += (c[i][j] == 'C');
            if(counter > 1) ans += (counter * (counter -1));
        }
 
        for(int i = 0; i < n; i++) {
            int counter = 0;
            for(int j = 0; j < n; j++)
                counter += (c[j][i] == 'C');
            if(counter > 1) ans += (counter * (counter -1));
        }
                 
        printf("%lld\n", ans / 2);
    }

	return 0; 
}
