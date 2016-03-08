#include <bits/stdc++.h>
#define MAX 102
#define INF 1000000

using namespace std;

int adj[MAX+1][MAX+1];

int floyd(){

	for(int k = 1; k <= MAX; k++)
		for(int i = 1; i <= MAX; i++)
			for(int j = 1; j <= MAX; j++)
				adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]); 
	int sum = 0;
	for(int i = 1; i <= MAX; i++)
		for(int j = 1; j <= MAX; j++)
			if(i != j && adj[i][j] != INF)
				sum += adj[i][j];
	return sum;
}

int main(){

	int x,y;
	int cont = 0;
	int c = 1;
	int visitado[MAX+1];

		for(int i = 1; i <= MAX; i++){
			visitado[i] = 0;
			for(int j = 1; j <= MAX; j++)
				adj[i][j] = INF;}

	while(scanf("%d %d",&x,&y) != EOF){
		if(x == 0 && y == 0 && cont != 0){
			printf("Case %d: average length between pages = %.3f clicks\n",c++,floyd()/(1.0*(cont*(cont-1))));
			
			cont = 0;
			for(int i = 1; i <= MAX; i++){
				visitado[i] = 0;
				for(int j = 1; j <= MAX; j++)
					adj[i][j] = INF;}
		}
		else{
		if(visitado[x] == 0){ cont += 1; visitado[x] = 1;}
		if(visitado[y] == 0){ cont += 1; visitado[y] = 1;}
		adj[x][y] = 1;}
	}

	return 0;
}
