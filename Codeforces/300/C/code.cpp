#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
using namespace std;

int n, m;
int answer = 0;
int d,h;
int db, hb;

bool can = true;

int bestone(int h1, int h,int d, int h2){
	return max(h1,max(h2,max(h1,h2) + (d - h)/2));
}

int main(){

	scanf("%d %d",&n,&m);
	scanf("%d %d",&db,&hb);
	answer = (db-1) + hb;

	for(int i = 1 ; i < m ;i++){
		scanf("%d %d",&d,&h);
		int height = abs(hb - h);
		int dif = d - db;
		if(height > dif) can = false;
		answer = max(answer, bestone(hb,height,dif,h));
		db = d;
		hb = h;
	}
	answer = max(answer,(n-db) + hb);
	
	if(can)
		printf("%d\n",answer);
	else printf("IMPOSSIBLE\n");

	return 0;
}
