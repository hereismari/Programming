#include <stdio.h>
#define MAX 110

using namespace std;

bool visitado[MAX];
int x[MAX];
int y[MAX];
int n;

void dfs(int v){
	visitado[v] = true;
	for(int i = 0; i < n ; i++)
		if(!visitado[i] && (x[v] == x[i] || y[v] == y[i]))
			dfs(i);
}
int main(){

	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d %d",&x[i],&y[i]);
		visitado[i] = false;
	}

	int cont = 0;
	for(int i = 0 ; i < n ; i++)
		if(!visitado[i]){
			dfs(i);
			cont++;
		}

	printf("%d\n",cont-1);
	return 0;
}
