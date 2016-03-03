#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

char graph[MAX][MAX];
bool visited[MAX][MAX];
int n,m;
bool cicle = false;

bool validate(int x, int y, int value){
	return  x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == value;
}

bool dfs(int x, int y, int parX, int parY){
	
	if(visited[x][y]) return true;
	visited[x][y] = true;
	
	if((x +1 != parX) && validate(x+1,y,graph[x][y]) && dfs(x+1,y,x,y))
		return true;
	if((x - 1 != parX) && validate(x-1,y,graph[x][y]) && dfs(x-1,y,x,y))
		return true;
	if((y+1 != parY) && validate(x,y+1,graph[x][y]) && dfs(x,y+1,x,y))
		return true;
	if((y -1 != parY) && validate(x,y-1,graph[x][y]) && dfs(x,y-1,x,y))
		return true;

	return false;
}

int main(){

	scanf("%d %d",&n,&m);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("\n%c",&graph[i][j]);

	for(int i = 0; i < n; i++)
		for(int j = 0 ; j < m; j++)
			if(!visited[i][j]){
				if(dfs(i,j,0,-1))
				{
					printf("Yes\n");
					return 0;
				}
			}

	printf("No");

	return 0;
}
