#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define MAX_V 55

ll INF = 1e11;

int n;
ll graph[MAX_V][MAX_V], dist[MAX_V][MAX_V];
int edge[MAX_V][MAX_V];

void clean_graph() {
  for(int i = 0; i < MAX_V; i++) {
    for(int j = 0; j < MAX_V; j++) {
      graph[i][j] = edge[i][j] = -1;
      dist[i][j] = INF;
    }
  }
}

void bfs(int index) {
  dist[index][index] = 0;
  priority_queue<pair<ll, int> >q;
  q.push(make_pair(0, index));

  while(!q.empty()) {
    
    pair<ll, int> f = q.top(); q.pop();
    ll d = f.first * -1;
    int par = f.second;
    
    for(int i = 1; i <= n; i++) {
      if(graph[par][i] != -1) {
        if(d + graph[par][i] < dist[index][i]) {
          dist[index][i] = d + graph[par][i];
          q.push(make_pair(dist[index][i] * -1, i));
          if(par != index) edge[index][i] = edge[index][par];
          else edge[index][i] = i; 
        }
      }
    }  
  }
  
  /*printf("bfs %d\n(%lld, %d) ", index, dist[index][1], edge[index][1]);
  for(int i = 2; i <= n; i++) {
    printf(" (%lld, %d)", dist[index][i], edge[index][i]); 
  }
  printf("\n");*/
}

double get_ans(int index) {

  ll mx = 0;
  int e = 0;
  for(int i = 1; i <= n; i++) {
    if(i != index && dist[index][i] > mx) {
      mx = dist[index][i];
      e = edge[index][i];
    }
  }
  
  ll mx2 = 0;
  for(int i = 1; i <= n; i++) {
    if(i == index) continue;
    if(edge[index][i] != e && dist[index][i] > mx2) {
      mx2 = dist[index][i];
    }
  }
  
  //printf("case %d: %lld %lld\n", index, mx, mx2);
  if(mx2 == 0) return mx;
  return mx - (mx-mx2)/2.0;
}


int main() {

  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; i++) {
    
    clean_graph();
    scanf("%d", &n);
    
    ll x;
    for(int j = 2; j <= n; j++) {
      for(int k = 1; k < j; k++) {
        scanf("%lld", &x);
        graph[j][k] = x;
        graph[k][j] = x;
      }
    }
    
    if(n == 2) {
      printf("Case #%d: %.6f\n", i, (graph[2][1]/2.0));
      continue;
    }
  
    for(int j = 1; j <= n; j++) bfs(j);
    
    double ans = INF;  
    for(int j = 1; j <= n; j++) ans = min(ans, get_ans(j));   
    
    printf("Case #%d: %.6f\n", i, ans);
  }


  return 0;
}
