#include <stdio.h>
#include <algorithm>

#define MAX 1001
using namespace std;

int n,k;
int list[MAX];
int sums[MAX];
int res;
int main(){

	while(scanf("%d %d",&n,&k) != EOF){
		list[0] = 0;
		for(int i = 1; i < n ; i++)
			scanf("%d",&list[i]);
		sums[0] = 0;
		for(int i = 1; i < n ;i++)
			sums[i] = list[i] - list[i-1];
		sort(sums, sums + n);
		
		res = 0;
		for(int i = 0 ; i <= n-k ;i++)
			res += sums[i];
		
		printf("%d\n",res);
	
	}
	return 0;
}
