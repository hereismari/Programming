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

#define MAX 1100  
#define INF 1000000000

#define ldd long double

int n, m;
ldd x, y;

struct point {

    ldd x, y;
    point(ldd a, ldd b) {
        x = a; y = b;
    }

    ldd dist(point b) {
        return (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y);
    }
};

struct edge {

    int from, to;
    ldd dist;

    edge(int f, int t, ldd d) {
        from = f; to = t; dist = d;
    }

    bool operator < (const edge &o) const {
        return dist < o.dist;
    }
};

vector<edge> e;
int unionF[MAX];

void reset() { for(int i = 0; i < MAX; i++) unionF[i] = i; }
int getPar(int a) { return (a == unionF[a]) ? a : unionF[a] = getPar(unionF[a]); }
bool isConnected(int a, int b) { return getPar(a) == getPar(b); }
void connect(int a, int b) { unionF[getPar(a)] = getPar(b); }

ldd solve() {
    ldd ans = 0;
    for(int i = 0; i < e.size(); i++) {
        if(!isConnected(e[i].from, e[i].to)) {
            ans = e[i].dist;
            connect(e[i].from, e[i].to);
        }
    }
    return sqrt(ans);
}

int main() {
 
    while(scanf("%d", &n) != EOF) {

        if(n == 0) break;
        e.clear();
        reset();
        vector<point> v;
        
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            v.pb(point(x, y));
        }

        for(int i = 0; i < n; i++) 
            for(int j = i+1; j < n; j++) {
                e.pb(edge(i, j, v[i].dist(v[j])));
            }

        sort(e.begin(), e.end());
        cout << fixed << setprecision(4) << solve() << endl;
    }

	return 0; 
}
