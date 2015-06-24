#include <bits/stdc++.h>
#define MAX 100
#define INF 100000000
#define S second
#define F first

using namespace std;

int adj1[MAX][MAX];
int adj2[MAX][MAX];

void floyd(){
	
	for(int k = 0 ; k < MAX; k++)
		for(int i = 0 ; i < MAX; i++)
			for(int j = 0 ; j < MAX; j++)
				adj2[i][j] = min(adj2[i][j], adj2[i][k] + adj2[k][j]);
	
	for(int k = 0 ; k < MAX; k++)
		for(int i = 0 ; i < MAX; i++)
			for(int j = 0 ; j < MAX; j++)
				adj1[i][j] = min(adj1[i][j], adj1[i][k] + adj1[k][j]);

}


void clear(){ 
	for(int i = 0; i < MAX ; i++)
		for(int j = 0 ; j < MAX; j++){
			adj1[i][j] = INF; 
			adj2[i][j] = INF;
			if(i == j){ adj1[i][j] = 0; adj2[i][j] = 0;}
	}
}

void answer(int x, int y){

	int mini = INF;
		for(int j = 0 ; j < MAX; j++){
			mini = min(mini, adj1[x][j] + adj2[y][j]);
		}
	if(mini == INF) printf("You will never meet.\n");
	else {
		printf("%d",mini);
			for(int j = 0 ; j < MAX; j++)
				if(adj1[x][j] + adj2[y][j] == mini) printf(" %c",'A' + j);
		printf("\n");
	}
}
int main(){
	
	int n;
	char a,di,x,y;
	int d;
	while(1){

		scanf("%d",&n);
		if(n == 0) break;
		clear();
		for(int i = 0; i < n; i++){		
			scanf("\n%c %c %c %c %d",&a,&di,&x,&y,&d);
			if(a == 'Y'){
				adj1[x-'A'][y-'A'] = min(d,adj1[x-'A'][y-'A']);
				if(di == 'B')		
					adj1[y-'A'][x -'A'] = min(d,adj1[y -'A'][x -'A']);
			}
			else{
				adj2[x-'A'][ y-'A'] = min(adj2[x-'A'][y-'A'],d);
				if(di == 'B')
					adj2[y-'A'][ x-'A'] = min(adj2[y-'A'][x-'A'],d);
			}
		}
	
		scanf("\n%c %c",&x,&y);
		floyd();
		answer(x-'A',y-'A');

	}
	return 0;
}
