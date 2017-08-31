#include <bits/stdc++.h>

using namespace std;

#define MAX 1010
#define INF 1e8

#define pii pair<int, int>
#define F first
#define S second

char graph[MAX][MAX];
int dist[3][MAX][MAX];

int n, m;

queue<pii> q;

const int dx[] = { 0, 1, 0,-1 };
const int dy[] = { 1, 0,-1, 0 };

bool isvalid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void setDist(int c) {
    while(!q.empty()) {
        pii front = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int x1 = front.F + dx[i], y1 = front.S + dy[i];
            if(!isvalid(x1, y1) || graph[x1][y1] == '#') continue;
            if(dist[c][x1][y1] > dist[c][front.F][front.S] + (graph[x1][y1] == '.')) {
                dist[c][x1][y1] = dist[c][front.F][front.S] + (graph[x1][y1] == '.');
                q.push(pii(x1, y1));
            }
        }
    }
}

int main() {
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("\n%s", graph[i]);
    
    for(int c = 0; c < 3; c++) {
        for(int i = 0; i < n; i++) fill(dist[c][i], dist[c][i]+m, INF);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(graph[i][j]-'1' == c) { dist[c][i][j] = 0; q.push(pii(i, j)); }
        setDist(c);
    }
    
    int ans = INF;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2*(graph[i][j] == '.'));
    
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}
