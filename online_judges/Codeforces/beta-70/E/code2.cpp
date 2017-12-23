#include <bits/stdc++.h>

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define MAX 20000

using namespace std;

const int INF = 100000010;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, t;
bool bad[11][11];

int d[11][11];

int matched[MAX];
bool visited[MAX];
vector<int> graph[MAX];

vector<pii> scie;
vector<pii> caps;
pii bomb;

bool match(int v) {
  if (visited[v]) return false;
  visited[v] = 1;
  for (auto to : graph[v]) {
    if (matched[to] == -1 || match(matched[to])) {
      matched[to] = v;
      return true;
    }
  }
  return false;
}

bool valid(int x, int y) {
  return x > 0 && y > 0 && x <= n && y <= n;
}

void bfs1() {

  for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = INF;

  d[bomb.F][bomb.S] = 0;
  queue<pii> q;
  q.push(mp(bomb.F, bomb.S));

  while(!q.empty()) {
    int x = q.front().F, y = q.front().S;
    q.pop();
    
    for(int dir = 0; dir < 4; dir++) {
      int x1 = x + dx[dir];
      int y1 = y + dy[dir];
      if (valid(x1, y1) && !bad[x1][y1] && d[x1][y1] == INF) {
        d[x1][y1] = d[x][y] + 1;
        q.push(mp(x1, y1));
      }
    }
  }
}

void bfs2(pii s, int i) {
  int dist[11][11];
  memset(dist, -1, sizeof dist);
  dist[s.F][s.S] = 0;

  queue<pii> q;
  q.push(mp(s.F, s.S));
  
  while(!q.empty()) {
    int x = q.front().F, y = q.front().S;
    q.pop();
    // if is x,y is closer to a scientist then a bomb and the scientist
    // can make it in time
    // check if it is a capsule, if it is then make an edge between
    // the scientist and the capsule
    if (d[x][y] >= dist[x][y] && dist[x][y] <= t) {
      for (int j = 0; j < caps.size(); j++) {
        if (mp(x, y) == caps[j]) {
          //printf("%d, %d ->%d %d, %d %d\n", s.F, s.S, x, y, i+1, j+1);
          graph[i + 1].pb(j + 1);
        }
      }
    }
    if(d[x][y] <= dist[x][y]) continue;
    for(int dir = 0; dir < 4; dir++) {
      int x1 = x + dx[dir];
      int y1 = y + dy[dir];
      if(valid(x1, y1) && !bad[x1][y1] && dist[x1][y1] == -1) {
        dist[x1][y1] = dist[x][y] + 1;
        q.push(mp(x1, y1));
      }
    }
  }

}

int main() {

  scanf("%d %d", &n, &t);
  
  char c;  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("\n%c", &c);
      if(isdigit(c)) {
        for(int cnt = 0; cnt < (c - '0'); cnt++) scie.pb(mp(i, j));
      } else {
        bad[i][j] = 1;
        if(c == 'Z') {
          bomb = mp(i, j);
        }
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("\n%c", &c);
      if(isdigit(c)) {
        for (int cnt = 0; cnt < (c - '0'); cnt++) caps.pb(mp(i, j));
      }
    }
  }

  // calculate distance from bomb
  bfs1();
  
  int N = scie.size();
  int M = caps.size();
  // calculate distance from scientists
  for(int i = 0; i < N; i++) {
    bfs2(scie[i], i);
  }
  
  memset(matched, -1, sizeof matched);
 
  int res = 0;
  for(int i = 1; i <= N; i++) {
    memset(visited, 0, sizeof visited);
    res += match(i);
  }
  
  printf("%d\n", res);
  return 0;
}
