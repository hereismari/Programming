#include <bits/stdc++.h>
#define MAX 501

using namespace std;

int m[MAX][MAX];
int sums[MAX];

int main(){

	int n,m1,q,x,y;
	scanf("%d %d %d",&n,&m1,&q);

	int answer = 0;
	int sum = 0;
	for(int i = 0 ; i < n; i++){
		sum = 0;
		for(int j = 0; j < m1; j++){
			scanf("%d",&m[i][j]);
			if(m[i][j] == 1) sum++;
			else {sums[i] = max(sum,sums[i]); sum = 0;}
		}
		sums[i] = max(sum,sums[i]);
	}
	
	for(int i = 0; i < q; i++){
		scanf("%d %d",&x,&y);
		x--; y--;
		if(m[x][y] == 0)
			m[x][y] = 1;
		else { m[x][y] = 0;}

		sum = 0;
		sums[x] = 0;
		for(int j = 0 ; j < m1; j++){
			if(m[x][j] == 1) sum++;
			else {sums[x] = max(sum,sums[x]); sum = 0;}
		}
		sums[x] = max(sum,sums[x]);
		answer = 0;
		for(int j = 0; j < n; j++)
			answer = max(answer,sums[j]);

		printf("%d\n",answer);
	}

	return 0;
}
