#include <stdio.h>
#include <vector>
#define MAX 100000
using namespace std;

int n,m;
int x,y;
bool visitado[MAX];

vector<vector<int> > adj(MAX);

void dfs(int i){

	visitado[i] = true;
	for(int j = 0 ; j < adj[i].size(); j++)
		if(!visitado[adj[i][j]])dfs(adj[i][j]);
}

int main(){

	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < m; i++){
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i = 1; i <= n ; i++)
		visitado[i] = false;
	int cont = 0;
	for(int i = 1; i <= n ; i++)
		if(!visitado[i]){
			dfs(i);
			cont++;}

	printf("%d\n",cont);

	return 0;
}
