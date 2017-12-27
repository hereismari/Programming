#include <bits/stdc++.h>

using namespace std;

#define MAX 20000

struct bipartite_graph {
	
    int V1, V2, *match;
    vector<int> *L;
    bool *visited;
    
    bipartite_graph(int MAX_V1, int MAX_V2) {
        L = new vector<int>[MAX_V1];
        visited = new bool[MAX_V2];
        match = new int[MAX_V2];
        V1 = MAX_V1; V2 = MAX_V2;
    }
     
    void clear() {
        for(int i = 0; i < V1; i++) { L[i].clear(); visited[i] = false; match[i] = 0; }
    }
    
    void add_edge(int v1, int v2) {
        L[v1].push_back(v2);
    }
    
    bool dfs(int u, int redo=0) {
    
        for(int i = L[u].size() - 1;i >= 0; i--){
            
            int v = L[u][i];
            
            if(!visited[v]) {
                visited[v] = true;
                if(match[v] == 0 || dfs(match[v], u)){
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    
    int maximum_matching(set<int> s) {
        int ans = 0;
        memset(match, 0, sizeof match);
        for(auto f: s) {
            fill(visited, visited + V1, false);
            ans += dfs(f);
        }
        return ans;
    }
};


int main() {
	
    int T, n, r, m, c;
    bipartite_graph G(MAX, MAX);
      
    while(scanf("%d %d", &n, &m) != EOF && (n || m)) {
      
      G.clear();
      
      scanf("%d", &T);
      
      int mat[120][120];
      for(int i = 0; i < 120; i++)
        for(int j = 0; j < 120; j++) mat[i][j] = 0;
 
      int x, y;
      for(int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &x, &y);
        mat[x][y] = 1;
      }
      
      set<int> s;
      
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j < m; j++) {
          if(mat[i][j] == 0 && mat[i][j+1] == 0) {
            //printf("%d %d\n", i , j);
            if((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1)) {
              G.add_edge(i * m + j, i * m + j + 1);
              s.insert(i * m + j);
            }
            else {
              G.add_edge(i * m + j + 1, i * m + j);
              s.insert(i * m + j + 1);
            }
          }
        }
      }
      
      for(int j = 1; j <= m; j++) {
        for(int i = 1; i < n; i++) {
          if(mat[i][j] == 0 && mat[i+1][j] == 0) {
            
            if((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1)) {
              G.add_edge(i * m + j, (i+1) * m + j);
              s.insert(i * m + j);
            }
            else {
              G.add_edge((i+1) * m + j, i * m + j);
              s.insert((i+1) * m + j);
            }
          }
        }
      }
 
      printf("%d\n", G.maximum_matching(s));
    }
    
    return 0;
}
