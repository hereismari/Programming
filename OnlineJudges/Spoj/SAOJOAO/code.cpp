#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;
int ext1, ext2;
vi adj[MAX];
int dist[MAX];
int maior;
bool visited[MAX];

void findExt1(int i, int d){

	visited[i] = true;
	if(d > maior){
		maior = d;
		ext1 = i;
	}

	for(int j = 0; j < adj[i].size(); j++)
		if(!visited[adj[i][j]])
			findExt1(adj[i][j],d + 1);		
}

void findExt2(int i, int d) {

	visited[i] = true;
	if(d > maior){
		maior = d;
		ext2 = i;
	}

	for(int j = 0; j < adj[i].size(); j++)
		if(!visited[adj[i][j]])
			findExt2(adj[i][j],d + 1);		

}

void setDist(int i, int d) {

	visited[i] = true;
	dist[i] = max(d,dist[i]);
	for(int j = 0; j < adj[i].size(); j++)
		if(!visited[adj[i][j]])
			setDist(adj[i][j],d + 1);		
}

int answer(int inicio, int passos){

	if(passos <= dist[inicio])
		return passos + 1;
	else
		return min(n,(passos - dist[inicio])/2 + dist[inicio] + 1);
}

int main() {
 
	scanf("%d",&n);
	ext1 = ext2 = 0;
	for(int i = 0; i < n-1; i++){
		scanf("%d %d",&x,&y);
		adj[x].pb(y);
		adj[y].pb(x);
	}

	maior = -1;
	memset(visited,false,sizeof visited);
	findExt1(1,0);
	maior = -1;
	memset(visited,false,sizeof visited);
	findExt2(ext1,0);

	memset(dist,0,sizeof dist);
	memset(visited,false,sizeof visited);
	setDist(ext1,0);
	memset(visited,false,sizeof visited);
	setDist(ext2,0);

//	printf("%d %d\n",ext1,ext2);
//	for(int i = 0; i < n; i++)
//		printf("%d ",dist[i]);

//	printf("\n");
	scanf("%d",&m);
	for(int i = 0; i < m ; i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",answer(x,y));
	}

	return 0; 
}
