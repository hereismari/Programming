#include <bits/stdc++.h>
#define MAX 10012

using namespace std;

vector<int> adj[MAX];
bool visit[MAX];
queue<int> q;
bool start[MAX];
bool flag;
int m,n,x,y;

void bfs(){

	if(!q.empty()){
		int top = q.front(); q.pop();
		printf("%d",top);
		visit[top] = true;
		for(int i = 0; i < adj[top].size(); i++)
			if(!visit[adj[top][i]]){
				q.push(adj[top][i]);
				visit[adj[top][i]] = true;
			}
	}

	while(!q.empty()){
		int top = q.front(); q.pop();
		printf(" %d",top);
		for(int i = 0; i < adj[top].size(); i++)
			if(!visit[adj[top][i]]){
				q.push(adj[top][i]);
				visit[adj[top][i]] = true;
			}
	}
	printf("\n");

}


int main() {

	while(true){
		scanf("%d %d",&m,&n);
		if(m == 0 && n == 0) break;
		
		flag = false;
		for(int i = 0 ; i <= m; i++) {
			visit[i] = false;
			start[i] = true;
			adj[i].clear();
		}
				
		for(int i = 0; i < n; i++){
			scanf("%d %d",&x,&y);
			adj[x].push_back(y);
			start[y] = false;
		}	

		for(int i = 1 ; i<=m; i++)
			if(start[i])
				q.push(i);
		bfs();	
	}

	return 0;
}
