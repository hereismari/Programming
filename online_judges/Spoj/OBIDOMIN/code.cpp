#include <bits/stdc++.h>
#define MAX 200

using namespace std;

int n, x, y;
int adj[MAX][MAX], grau[MAX];
bool visited[MAX];

void dfs(int k) {
    visited[k] = true;
    for(int i = 0; i < 7; i++)
        if(!visited[i] && adj[k][i] == 1) dfs(i);
}

bool conectado() {
	int k;
	for(k = 0; k < 7 && grau[k] == 0; k++);
	dfs(k);
	for(int i = 0; i < 7; i++) if (grau[i] > 0 && !visited[i]) return false;
	return true;
}

int main() {

    int teste = 1;
    while(true) {

        memset(visited, false,sizeof visited);
	memset(adj, 0, sizeof adj);
	memset(grau, 0, sizeof grau);

        scanf("%d",&n);

        if(n == 0) break;
        for(int i = 0; i < n; i++){
		scanf("%d %d",&x,&y);
		adj[x][y] = adj[y][x] = 1;
		grau[x]++; grau[y]++;
	}
        
        printf("Teste %d\n", teste++);
	int impar = 0;
	for(int i = 0; i < 7; i++) impar += grau[i] % 2;
        
	if((impar > 2) || !conectado()) printf("nao\n\n");
	else printf("sim\n\n");
    }

    return 0;
}