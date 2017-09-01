#include <stdio.h>
#include <vector>

#define MAX 100000

using namespace std;

int n;
int v1,v2,value;

vector<int> adj[MAX];
bool visited[MAX];
int marked;

long long int answer;

void dfs(int v){
		marked++;
		visited[v] = true;
		for(int j = 0 ;  j < (int)adj[v].size() ; j++)
			if(!visited[adj[v][j]])
				dfs(adj[v][j]);
}

int main(){

	scanf("%d",&n);
	for(int i = 0 ; i < n; i++)
		visited[i] = false;
	
	for(int i = 0 ; i < n-1 ; i++){
		scanf("%d %d %d",&v1,&v2,&value);
		if(value == 0){
			adj[v1-1].push_back(v2-1);
			adj[v2-1].push_back(v1-1);
		}
	}
	
	answer = (long long int)(n * (n-1))/2;

	for(int i = 0 ; i < n ;i++)
	{
		if(!visited[i]){
			marked = 0;	
			dfs(i);
			answer -= (long long int) (marked * (marked-1))/2;
		}
	}

	printf("%lld\n",answer);
	return 0;
}
