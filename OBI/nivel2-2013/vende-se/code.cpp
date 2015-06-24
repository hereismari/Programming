#include <stdio.h>
#include <algorithm>

#define min(a,b) (a < b ? a : b)
#define MAX 1000001
#define INF 1000000000
using namespace std;

int main(){
	
	int n,k;
	int array[MAX];

	scanf("%d %d",&n,&k);

	for(int i = 0 ; i < n ; i++)
		scanf("%d",&array[i]);
	
	sort(array,array+n);
	int answer = INF;
	for(int i = 0 ; i <= k; i++)
		answer = min(answer, array[n-(k-i+1)]-array[i]);
	printf("%d\n",answer); 

	return 0;
}
