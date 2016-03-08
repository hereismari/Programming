#include <bits/stdc++.h> 

#define MAX 2100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;
char s[MAX];
bool special[MAX];
pii pd[MAX][MAX];
bool vis[MAX][MAX];

pii ans(int l, int r) {

    if(l == r) return pd[l][r] = mp(special[l], 1);
    if(l > r) return pd[l][r] = mp(0,0);
    if(vis[l][r]) return pd[l][r];

    pii answer = mp(0,0);
    if(s[l] == s[r]) {
      pii aux = ans(l+1, r-1);
      answer = max(answer, mp(aux.F + special[l] + special[r], aux.S + 2));
    }

    answer = max(answer, max(ans(l+1,r), ans(l, r-1))); 
    vis[l][r] = true;
    return pd[l][r] = answer;
}

int main() {
 
    while(scanf("\n%s %d", s, &n) != EOF) {

        int len = strlen(s);

        memset(special, false, sizeof special);
        memset(vis, false, sizeof vis);

        for(int i = 0; i < n; i++) { scanf("%d", &x); special[x-1] = true; }
        printf("%d\n", ans(0, len-1).S);
   }

	return 0; 
}
