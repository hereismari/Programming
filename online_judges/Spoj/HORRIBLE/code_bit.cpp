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

#define MAX 100100  
#define INF 1000000000

int n, m, x, y;
int p, q, c, t;
ll v, bit[MAX];

void clearBIT() {
  memset(bit, 0, sizeof bit);
  memset(a, 0, sizeof a);
}

ll getBIT(int x) {
  ll res = 0;
  while(x > 0) {
    res += bit[x];
    x -= (x & -x);
  }
  
  return res;
}

void updateBIT(int x, int v) {
  while(x < MAX) {
    bit[x] += v;
    x += (x & -x);
  }
}


ll getQuery(int l, int r) { 
  return getBIT(r) - getBIT(l-1);
}

void update(int l, int r, ll v) { 
    updateBIT(l, v);
    updateBIT(l+1, -v);
}

int main() {

    scanf("%d", &t);
    while(t--) {

        scanf("%d %d", &n, &m);
        clearBIT();

        for(int i = 0; i < m; i++) {
            scanf("%d", &c);
            if(c == 0) {
                scanf("%d %d %lld", &p, &q, &v);
                updateLazy(p, q, v);
            }
            else {
                scanf("%d %d", &p, &q);
                printf("%lld\n", getQuery(p, q));
            }
        }
    }

    return 0; 
}
