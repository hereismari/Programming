#include <bits/stdc++.h>
#define MAX 3010

using namespace std;

vector<int> edge[MAX];
bool vis[MAX];
int d[MAX][MAX];
int n,m;
int u,v;

void bfs(){

	queue<int> q;
    for(int i = 1; i <= n; ++i){
        memset(vis,0,sizeof(vis));
        while(!q.empty()) q.pop();
        
		q.push(i);
        vis[i] = 1;
        d[i][i] = 0;
        
		while(!q.empty()){
            u = q.front(); q.pop();
            for(int j = 0; j < edge[u].size(); ++j){
                v = edge[u][j];
                if(!vis[v]){
                    vis[v] = 1;
                    d[i][v] = d[i][u]+1;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    
    int s1,t1,d1,s2,t2,d2;

    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
	scanf("%d %d %d %d %d %d",&s1,&t1,&d1,&s2,&t2,&d2);
	bfs(); 
	if(d[s1][t1] > d1 || d[s2][t2] > d2){
        printf("-1\n");
        return 0;
    }

    int ans = d[s1][t1] + d[s2][t2];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(d[s1][i]+d[i][j]+d[j][t1]<=d1&&d[s2][i]+d[i][j]+d[j][t2]<=d2)
                ans=min(ans,d[s1][i]+d[i][j]+d[j][t1]+d[s2][i]+d[j][t2]);
            if(d[s1][i]+d[i][j]+d[j][t1]<=d1&&d[t2][i]+d[i][j]+d[j][s2]<=d2)
                ans=min(ans,d[s1][i]+d[i][j]+d[j][t1]+d[t2][i]+d[j][s2]);
        }
    }

    cout << m-ans << endl;

    return 0;
}
