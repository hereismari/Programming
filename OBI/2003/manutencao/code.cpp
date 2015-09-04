#include <bits/stdc++.h>
#define pb push_back
#define MAX 500
#define WHITE 0
#define BLACK 1
#define GREY 2

using namespace std;

vector<int> adj[MAX];
int art_point[MAX], id[MAX], min_id[MAX], color[MAX];
int cont, n, m, x , y, rootChildren, root;

void findPoints(int x, int par) {

    color[x] = GREY;
    id[x] = min_id[x] = cont++;

    for(int i = 0; i < adj[x].size(); i++){
        int v = adj[x][i];
        if(color[v] == WHITE){

            if(x == root) rootChildren++;

            findPoints(v, x);
            if(min_id[v] >= id[x] && x != root) art_point[x] = true;
            min_id[x] = min(min_id[x], min_id[v]);
        }
        else if(v != par && color[v] == GREY) min_id[x] = min(min_id[x], id[v]);
    }
    color[x] = BLACK;
}

int main() {

    int teste = 1;
    while(scanf("%d %d",&n,&m) == 2 && n > 0) {

        for(int i = 0; i <= n; i++) adj[i].clear();
        memset(color, WHITE, sizeof color);
        memset(art_point, false, sizeof art_point);
        cont = 1;
        for(int i = 0; i < m; i++) {
            scanf("%d %d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
	root = 1;
        rootChildren = 0;
        findPoints(1,1);
	if(rootChildren > 1) art_point[1] = true;
        printf("Teste %d\n", teste++);
        bool flag = false;
        for(int i = 1; i <= n; i++){
            if(art_point[i] && flag)
                printf(" %d",i);
            else if(art_point[i]) {printf("%d",i); flag = true;}
        }
        if(!flag) printf("nenhum");
        printf("\n\n");
    }
    return 0;
}
