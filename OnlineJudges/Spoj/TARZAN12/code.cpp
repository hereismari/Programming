#include <bits/stdc++.h>
#define MAX 1000010

using namespace std;

bool visited[MAX] = {false};
vector<int> adj[MAX];

bool dist(int x1, int x2, int y1, int y2, int d){
	return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= pow(d,2));
}


void bfs(int x){
	visited[x] = true;
	for(int i = 0; i< adj[x].size(); i++)
		if(!visited[adj[x][i]])
			bfs(adj[x][i]);
}

int x[MAX];
int y[MAX];

int main(){

	int n,d;
	scanf("%d %d",&n,&d);
	for(int i = 0; i < n; i++){
		scanf("%d %d",&x[i],&y[i]);
	}

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++)
			if(dist(x[i],x[j],y[i],y[j],d))
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}	
	}

	bfs(0);
	for(int i = 1; i < n; i++)
		if(!visited[i])
		{
			printf("N\n");
			return 0;
		}

	printf("S\n");
	return 0;
}
