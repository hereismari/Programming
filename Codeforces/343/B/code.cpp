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

int n, x, y;
char c;

int main() {
 
    while(scanf("%d", &n) != EOF){
        
        int f[400], m[400];
        memset(f, 0, sizeof f);
        memset(m, 0, sizeof m);

        for(int i = 0; i < n; i++) {
            scanf("\n%c %d %d", &c, &x, &y);
            if(c == 'F') for(int i = x; i <= y; i++) f[i]++;
            if(c == 'M') for(int i = x; i <= y; i++) m[i]++;
        }

        int ans = 0;
        for(int i = 1; i <= 366; i++)
            ans = max(ans, min(f[i], m[i]));
        printf("%d\n", ans*2);

    }

	return 0; 
}
