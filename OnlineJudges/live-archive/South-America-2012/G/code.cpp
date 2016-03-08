#include <bits/stdc++.h>

using namespace std;

#define MAX 5001
#define UNMATCHED -1   
#define pb push_back

vector<int> graph[MAX + 1];
int matched[MAX], used[MAX];
bool visited[MAX];

int n,m;
char g[100][100];  

bool augment_path(int id) {
 
  visited[id] = true;
 
  for(int i = 0; i < graph[id].size(); i++) {
    int neigh = graph[id][i];
    if(visited[neigh]) continue;
 
    if(matched[neigh] == UNMATCHED) {
        matched[id] = neigh; matched[neigh] = id;
        return true;
    } 
    else if(matched[neigh] != id) {
        visited[neigh] = true;
        if (augment_path(matched[neigh])) {
            matched[id] = neigh; matched[neigh] = id;
            return true;
        }
    }
  }
 
  return false;
}
   
int main() {
 
    int dir_x[4] = {-1, 1, 0, 0};
    int dir_y[4] = {0, 0, -1, 1};
    
    while(scanf("%d %d", &n, &m) != EOF) {
        
		memset(matched, -1, sizeof matched);
		memset(used, false, sizeof used);
		for(int k = 0; k < MAX; k++)
        	if(graph[k].size()!=0)
            	graph[k].clear();

        for(int i = 0; i < n; i++) scanf("\n%s", g[i]);
         
        int cont = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 'X') continue;
                cont++;

				for(int k = 0; k < 4; k++) {
					int x = i + dir_x[k];
					int y = j + dir_y[k];

					if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] != 'X') {
						graph[i*m + j].pb(x*m + y);
                        used[i*m +j] = used[x*m +y] = true;				
                    }				
				}
            }

        if(cont % 2 == 1) { printf("1\n"); continue; }

		int answer = 0;
 		for(int i = 0; i < MAX; i++) {
            if(matched[i] == UNMATCHED && used[i]) {
                fill(visited, visited + MAX, false);
      			if(augment_path(i)) answer++;
    		}
		}

		printf("%c\n", answer == cont/2 ? '2' : '1');
	
    }
     
    return 0;    
}
