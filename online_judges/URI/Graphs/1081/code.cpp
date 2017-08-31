#include <bits/stdc++.h>
#define MAX 30

using namespace std;

bool adj[MAX][MAX];
bool visit[MAX];
int v,e,x,y,n,m;
bool flag;

void init1() {
	for(int i = 0; i < MAX; i++){
		for(int j = 0 ; j < MAX; j++)
			adj[i][j] = false;
		visit[i] = false;
	}
}

void dfs(int x, int b, int dist) {
	visit[x] = true;
	
	for(int i = 0; i < v+1; i++){
		if(adj[x][i] && !visit[i]){
			cout << setw(dist + x/10);
			cout << x << "-" << i;
			cout << " pathR(G," << i << ")" << "\n" ;
			dfs(i, b, dist + 2 + x/10);
		}
		else if(adj[x][i])
			cout << setw(dist + x/10) << x << "-" << i << "\n";
	}
}

int main() {

	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		init1();
		scanf("%d %d",&v,&e);
		for(int j = 0; j < e; j++){
			scanf("%d %d",&x,&y);
			adj[x][y] = true;
		}	
		flag = false;
		cout << "Caso " << i+1 << ":\n";
		for(int i = 0; i < v+1; i++)
			if(!visit[i]){
				bool ok = false;
				for(int j = 0; j < MAX; j++)
					if(adj[i][j])
						ok = true;
				if(!ok) continue;
				if(flag) printf("\n");
				dfs(i,i,3);
				flag = true;
			}
		
		cout <<"\n";
	}
	return 0;
}
