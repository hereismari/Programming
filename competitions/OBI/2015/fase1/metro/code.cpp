#include <bits/stdc++.h>
#define MAX 20020

using namespace std;

vector<int> graph[MAX];
int n,m,a,b;
int start, center;
bool visited[MAX] = {false};
int answer;

int dfs(int x, int par, int cont){
    visited[x] = true;
	for(int i = 0 ; i < graph[x].size(); i++){
	    int node = graph[x][i];
		if(node == start && par != start)  {
			answer = cont+1; break;
		}
		if(!visited[node] && node != par && node != center)
			dfs(node, x, cont + 1);
	}
}

int main(){

	scanf("%d %d",&m,&n);
	answer = -1;
	for(int i = 0 ; i < n ;i++){
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);

		if(graph[a].size() >= 5) center = a;
		if(graph[b].size() >= 5) center = b;
	}

	for(int i = 1; i <= n; i++){
		if(graph[i].size() == 4 || graph[i].size() == 3)
		{
			start = i;
			dfs(i,i,0);
			printf("%d\n",answer);
			 return 0;
		}
	}

	return 0;
}
