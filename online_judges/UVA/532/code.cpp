#include <bits/stdc++.h>
#define MAX 100
#define INF 100000
#define S second
#define F first
#define mp(a,b) make_pair(a,b)
using namespace std;
int b1, b2,b3;
int e1, e2,e3;
char adj[MAX][MAX][MAX];

int bfs(){

	int dist[MAX][MAX][MAX];
	bool visit[MAX][MAX][MAX];
	for(int i = 1; i < MAX; i++)	
		for(int j = 1; j < MAX; j++)	
			for(int k = 1; k < MAX; k++)	
				{dist[i][j][k] = INF; visit[i][j][k] = false;}

	queue< pair<int,pair<int,int> > > fila;
	fila.push(mp(b1,make_pair(b2,b3)));
	dist[b1][b2][b3] = 0;
	visit[b1][b2][b3] = true;

	while(!fila.empty()){
		int id = fila.front().F;
		int i1 = fila.front().S.F;
		int j1 = fila.front().S.S;
		fila.pop();
		if(adj[id-1][i1][j1] != '#' && !visit[id-1][i1][j1]){
			fila.push(mp(id-1,mp(i1,j1)));
			visit[id-1][i1][j1] = true;
			dist[id-1][i1][j1] = dist[id][i1][j1] + 1;
		}
		if(adj[id+1][i1][j1] != '#' && !visit[id+1][i1][j1]){
			fila.push(mp(id+1,mp(i1,j1)));
			visit[id+1][i1][j1] = true;
			dist[id+1][i1][j1] = dist[id][i1][j1] + 1;
		}
		if(adj[id][i1+1][j1] != '#' && !visit[id][i1+1][j1]){
			fila.push(mp(id,mp(i1+1,j1)));
			visit[id][i1+1][j1] = true;
			dist[id][i1+1][j1] = dist[id][i1][j1] + 1;
		}
		if(adj[id][i1-1][j1] != '#' && !visit[id][i1-1][j1]){
			fila.push(mp(id,mp(i1-1,j1)));
			visit[id][i1-1][j1] = true;
			dist[id][i1-1][j1] = dist[id][i1][j1] + 1;
		}
		if(adj[id][i1][j1-1] != '#' && !visit[id][i1][j1-1]){
			fila.push(mp(id,mp(i1,j1-1)));
			visit[id][i1][j1-1] = true;
			dist[id][i1][j1-1] = dist[id][i1][j1] + 1;
		}
		if(adj[id][i1][j1+1] != '#' && !visit[id][i1][j1 +1]){
			fila.push(mp(id,mp(i1,j1+1)));
			visit[id][i1][j1+1] = true;
			dist[id][i1][j1+1] = dist[id][i1][j1] + 1;
		}
	}

	return adj[e1][e2][e3];
}

void reset(){
	for(int i = 0; i < MAX; i++)	
		for(int j = 1; j < MAX; j++)	
			for(int k = 1; k < MAX; k++)	
				{adj[i][j][k] = '#';}

}


int main(){
	int l,r,c;
	while(1){
		scanf("%d %d %d",&l,&r,&c);
		if(l == 0) break;
		reset();
		for(int i = 1 ; i <= l; i++){
			
			for(int j = 1; j <= r; j++)
				for(int k = 1; k <= c; k++){
					scanf("\n\n%c",&adj[i][j][k]);
						if(adj[i][j][k] == 'S') 
						{
							b1 = i; b2 = j; b3 = k;
						}
						if(adj[i][j][k] == 'E')
						{
							e1 = i; e2 = j; e3 = k;
						}				
				}
		}
		
		int answer = bfs();
		if(answer < INF) printf("Escaped in %d minute(s).\n",answer);
		else printf("Trapped!\n");

	}
	return 0;
}
