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
int a[5];

int sequence() { return (a[4] == a[3] + 1 && a[3] == a[2] + 1 && a[2] == a[1] + 1 && a[1] == a[0] + 1) ? a[0] : 0; }
int four() { 
    if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) return a[0];
    else if(a[1] == a[2] && a[2] == a[3] && a[3] == a[4]) return a[1];
    else return 0;
}

int trio_par() {
    if(a[0] == a[1] && a[1] == a[2] && a[3] == a[4]) return a[0];
    else if(a[0] == a[1] && a[2] == a[3] && a[3] == a[4]) return a[2];
    else return 0;
}

int trio() {
    if(a[0] == a[1] && a[1] == a[2]) return a[0];
    else if(a[1] == a[2] && a[2] == a[3]) return a[1];
    else if(a[2] == a[3] && a[3] == a[4]) return a[2];
    else return 0;
}

pair<int,int> pars() {
    if(a[0] == a[1] && a[2] == a[3]) return mp(max(a[0], a[2]), min(a[0], a[2]));
    else if(a[0] == a[1] && a[3] == a[4]) return mp(max(a[0], a[3]), min(a[0], a[3]));
    else if(a[1] == a[2] && a[3] == a[4]) return mp(max(a[1], a[3]), min(a[1], a[3]));
    else return mp(0,0);
}

int par() {
    int res = 0;
    if(a[0] == a[1]) res = max(res, a[0]);
    else if(a[1] == a[2]) res = max(res, a[1]);
    else if(a[2] == a[3]) res = max(res, a[2]);
    else if(a[3] == a[4]) res = max(res, a[3]);
    return res;
}

void solve() {

    sort(a, a + 5);
    if(sequence()) printf("%d\n\n", sequence() + 200);
    else if(four()) printf("%d\n\n", four() + 180);
    else if(trio_par()) printf("%d\n\n", trio_par() + 160);
    else if(trio()) printf("%d\n\n", trio() + 140);
    else if(pars().F) printf("%d\n\n",pars().F*3 + pars().S*2 + 20);
    else if(par()) printf("%d\n\n", par());
    else printf("%d\n\n", 0);
}

int main() {
 
    scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 5; j++) scanf("%d", &a[j]);
            printf("Teste %d\n", i);
            solve();
        }

	return 0; 
}
