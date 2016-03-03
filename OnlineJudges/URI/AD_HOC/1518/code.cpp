#include <bits/stdc++.h> 

#define MAX 1010 
#define EPS 1e-7
#define LIMIT 1001
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y, aux_x, aux_y, t;
int t_x[3], t_y[3];
char t_dir[3];
int vis[MAX][MAX];

pii bfs(int x1, int y1, int x2, int y2, int i) {

    printf("x1,y1 %d %d\n", x1, y1);
    priority_queue<pair<int, pii > > q;
    q.push(mp(0,mp(x1,y1)));

    while(!q.empty()) {

        pii pos = q.top().S;
        int v = -(q.top().F);
        q.pop();
        if(vis[pos.F][pos.S] || pos.F < 0 || pos.F > LIMIT || pos.S < 0 || pos.S > LIMIT) break;
        if(pos.F == x2  + (t_dir[i] == 'D')*v && pos.S == y2 + v*(t_dir[i] == 'C'))
        {
            t += v;
            printf("(%d, %d)\n", pos.F, pos.S);
            return pos;
        }
        vis[pos.F][pos.S] = true;
        printf("%d %d %d\n", v, pos.F, pos.S);
        q.push(mp(-(-v + 1), mp(pos.F + 1, pos.S + 1)));  
        q.push(mp(-(-v + 1), mp(pos.F + 1, pos.S - 1)));  
        q.push(mp(-(-v + 1), mp(pos.F - 1, pos.S + 1)));  
        q.push(mp(-(-v + 1), mp(pos.F - 1, pos.S - 1)));

        q.push(mp(-(-v + 1), mp(pos.F + 2, pos.S)));  
        q.push(mp(-(-v + 1), mp(pos.F - 2, pos.S)));  
        q.push(mp(-(-v + 1), mp(pos.F, pos.S - 2)));  
        q.push(mp(-(-v + 1), mp(pos.F, pos.S + 2)));  
    }

}

int solve(int f, int m, int l) {
    t = 0;
    pii pos;
    
    memset(vis, false, sizeof vis);
    pos = bfs(x, y, t_x[f], t_y[f], f);
    memset(vis, false, sizeof vis);
    pos = bfs(pos.F, pos.S, t_x[m], t_y[m], m);
    memset(vis, false, sizeof vis);
    bfs(pos.F, pos.S, t_x[l], t_y[l], l);
    return t;
}

int main() {
 
    while(scanf("%d %d", &x, &y) && (x || y)){
        for(int i = 0; i < 3; i++)
            scanf("%d %d %c", &t_x[i], &t_y[i], &t_dir[i]);
        
        int ans = INT_MAX;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3; k++)
                    if(i != j && i != k && j != k) ans = min(ans, solve(i,j,k));

        printf("%d\n", ans);
    }

	return 0; 
}
