#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

using namespace std;

int n,m;
int array[MAX];
int counter[MAX];
bool possible;

int main(){

	while(1){

	scanf("%d %d",&n,&m);
	if(n == 0 && m == 0) break;
	
	possible = true;
	memset(counter,0,sizeof(counter));
	
	for(int i = 0 ; i < m ; i++)
		scanf("%d",&array[i]);
	for(int i = 0 ; i < m ; i++)
		for(int j = i; j < m ; j++)
			counter[abs(array[i]-array[j])]++;

	for(int i = 0 ; i <= n ; i++)
		if(counter[i] <= 0)
			possible = false;
	printf("%c\n",possible?'Y':'N');

	}

	return 0;
}
