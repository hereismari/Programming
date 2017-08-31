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

int n, m, x, y;

struct triangle {
    
    int l[3];
    double color;

    triangle(int l1, int l2, int l3, double c) {
        l[0] = l1; l[1] = l2; l[2] = l3; color = c;
    }

    bool operator < (const triangle &o) const {
        return color < o.color;
    };
};

bool match(triangle t1, triangle t2) { 
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(t1.l[i] == t2.l[j]) return true;
    return false;
}

vector<int> graph[MAX];
int dist[MAX];
void reset() {
    for(int i = 0; i < MAX; i++) { graph[i].clear(); dist[i] = 0; }
}

int bfs(int index) {

    int res = 0;

    dist[index] = 1;
    queue<int> q;
    q.push(index);

    while(!q.empty()) {
        int front = q.front(); q.pop();
        res = max(res, dist[front]);
        for(int i = 0; i < graph[front].size(); i++) {
            int neigh = graph[front][i];
            if(dist[neigh] < dist[front] + 1) {
                dist[neigh] = dist[front] + 1;
                q.push(neigh);
            }
        }
    }

    return res;
}

int main() {
 
    while(scanf("%d", &n) != EOF) {

        reset();
        int l1, l2, l3;
        double c;

        vector<triangle> v;
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d %lf", &l1, &l2, &l3, &c);
            v.pb(triangle(l1, l2, l3, c));
        }
        
        sort(v.begin(), v.end());

        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(v[i].color != v[j].color && match(v[i], v[j])) { graph[i].pb(j); }

        int ans = 0;
        for(int i = 0; i < n; i++) 
            if(!dist[i]) ans = max(ans, bfs(i));
        
        printf("%d\n", ans);
    }

	return 0; 
}
