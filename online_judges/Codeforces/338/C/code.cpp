#include <bits/stdc++.h> 

#define MAX 2110 
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

int n, m, dp[MAX];
pii p[MAX];
char s[MAX], t[MAX];
map<string, pii > pieces;

int solve() {
    
    int res[m+1];
   
    for(int i = 0; i < m; i++) {
        res[i] = MAX * 2;
        string aux = "";
        for(int j = i; j >= 0; j--) {
            aux += t[j];
            if(pieces.find(aux) != pieces.end()) {
                
                int first = (pieces.find(aux)->S).F;
                int sec = (pieces.find(aux)->S).S;

                if(j == 0) { res[i] = 1; p[i] = mp(first, sec); }
                else if(res[j - 1] + 1 < res[i]) {
                    p[i] = mp(first, sec);
                    res[i] = 1 + res[j-1];
                }
            }
        }
    }
    return res[m-1];
}

int main() {
 
    scanf("%s\n%s", s, t);
    n = strlen(s);
    m = strlen(t);

    for(int i = 0; i < n; i++) {
        string aux = "";
        for(int j = i; j < n; j++) {
            aux += s[j];
            pieces[aux] = mp(i,j);
        }
    }
 
    for(int i = n-1; i >= 0; i--) {
        string aux = "";
        for(int j = i; j >=0; j--) {
            aux += s[j];
            pieces[aux] = mp(i,j);
        }
    }
    
    int ans = solve();
    if(ans != MAX * 2) {
        printf("%d\n", ans);
        int cont = ans-1, cont2 = m-1;
        pii ans2[ans];
        while(cont >= 0) {
            ans2[cont] = p[cont2];
            cont2 -= abs(p[cont2].F - p[cont2].S) + 1;
            cont--;
        }

        for(int i = 0; i < ans; i++) {
            printf("%d %d\n", ans2[i].S + 1, ans2[i].F + 1);
        }
    }
    else printf("-1\n");

	return 0; 
}
