#include<bits/stdc++.h>
#define MAX 10000
#define F first
#define S second
#define p pair<int,int>
#define mp make_pair

using namespace std;

int n;
char matriz[MAX][MAX];
int answer[MAX][MAX];
queue<p> q;

bool isValid(int i, int j, int dist){
	return (i >= 0 && j >= 0 && i < n && j < n && dist < answer[i][j]);
}

void update(int x, int y, int dist){
	answer[x][y] = dist;
	q.push(mp(x,y));
}

void bfs(){

	while(!q.empty()){
		p top = q.front(); q.pop();
		int dist = answer[top.F][top.S] + 1;
		if(isValid(top.F + 1, top.S,dist)) update(top.F + 1, top.S,dist);
		if(isValid(top.F - 1, top.S,dist)) update(top.F - 1, top.S,dist);
		if(isValid(top.F, top.S + 1,dist)) update(top.F,top.S + 1,dist);
		if(isValid(top.F, top.S - 1,dist)) update(top.F, top.S - 1,dist);
	}	
}

int main(){

	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j< n; j++){
			scanf("\n%c",&matriz[i][j]);
			if(matriz[i][j] == '0'){
				q.push(mp(i,j));
				answer[i][j] = 0;
			}
			else
				answer[i][j] = 9;
		}

	bfs();
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n; j++){
			printf("%d",answer[i][j]);
		}
		printf("\n");
	}	

	return 0;
}
