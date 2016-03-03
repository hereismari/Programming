#include <stdio.h>
#define min(a,b) (a < b ? a: b)
#define INF 100000
using namespace std;

int dfs(int x, int y){
	
	if(x == y) return 1;
	
	if(x-1 > y) return INF;
	if(x < 1) return INF;
	
	return min(dfs(x-1,y),dfs(x*2,y)) + 1;	
}


int main(){

	int n,m;
	scanf("%d %d",&n,&m);

	printf("%d\n",dfs(n,m));
	return 0;
}
