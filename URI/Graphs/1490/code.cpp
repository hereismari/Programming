#include <bits/stdc++.h>

#define UNMATCHED -1
#define MAX 500000
#define vi vector<int>
#define A 1
#define B 0
#define pb push_back

using namespace std;

int size1, size2, n;
vi graph[MAX];
int matched[MAX];
bool visited[MAX];

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

    int id = 0;
    while(scanf("%d",&n) != EOF){

        memset(matched, UNMATCHED, sizeof matched);
        for(int i = 0; i < id; i++) graph[i].clear();
        char c[n][n];
        int row[n][n];
        int col[n][n];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("\n%c",&c[i][j]);

        id = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(c[i][j] != 'X')
                    row[i][j] = id;
                else id++;
            }
            id++;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(c[j][i] != 'X')
                    col[j][i] = id;
                else id++;
            }
            id++;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                if(c[i][j] != 'X')
                {
                    graph[row[i][j]].pb(col[i][j]);
                    graph[col[i][j]].pb(col[i][j]);
                }
        }

        int answer = 0;
        for(int i = 1; i < id; i++) {
            if(matched[i] == UNMATCHED) {
                memset(visited, false, sizeof visited);
                if(augment_path(i)) answer++;
            }
        }

         printf("%d\n", answer);
    }
  return 0;
}
