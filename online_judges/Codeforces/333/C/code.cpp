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

#define MAX 402 
#define INF 10000010

int n, m, x, y;

int graph[MAX][MAX];
int dist[MAX];

int bfs(bool value) {
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while(!q.empty()) {
        
        int top = q.front(); q.pop();
        for(int i = 1; i <= n; i++) {
            if(graph[top][i] == value && dist[top] + 1 < dist[i]) {
                dist[i] = dist[top] + 1;
                q.push(i);
            }
        }
    }

    return (dist[n] == INF ? -1 : dist[n]);
}

int main() {
 
	scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) dist[i] = INF;
    
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = true;
        graph[y][x] = true;
    }


    printf("%d\n", bfs(!graph[1][n]));

    return 0; 
}
