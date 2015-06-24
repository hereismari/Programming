#include <stdio.h>
#include <string.h>
#define MAX 1001

using namespace std;

int n;
int l[MAX];

int dp(){

	int max = 0;
	int res[MAX];
	memset(res,1,sizeof(res));

	for(int i = 0 ; i < n ; i++)
	{	
		res[i] = 1;
		for(int j = 0; j < i; j++)
			if(l[i] > l[j] && res[i] <= res[j])
				res[i] = res[j] + 1;
	}
	
	for(int i = 0; i < n ; i++)
		if(res[i] > max)
			max = res[i];
	return max;
}

int main() {


	scanf("%d",&n);

	for(int i = 0 ; i < n ; i++)
		scanf("%d",&l[i]);

	printf("%d\n",dp());
	return 0;
}
