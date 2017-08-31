#include <bits/stdc++.h>
#define MAX 110000
#define ll long long int
using namespace std;

vector<int> adj[MAX];
bool visited[MAX];
ll answer;
ll num;

void dfs(int x){

	num++;
	visited[x] = true;
	for(int i = 0 ; i < adj[x].size(); i++)
		if(!visited[adj[x][i]])
			dfs(adj[x][i]);
}

int main() {
	
	int n;
	scanf("%d",&n);
	
	for(int i = 0 ; i < n-1; i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(c == 0){
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	answer = ((n-1)*n)/2;	
	
	for(int i = 1; i <= n; i++)
		if(!visited[i]){
			num = -1; dfs(i);
			answer -= ((num + 1) * (num))/2;

		}
	
	printf("%lld\n",answer);
	return 0;
}


