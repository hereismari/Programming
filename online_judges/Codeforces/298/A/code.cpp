#include <stdio.h>
#include <algorithm>

#define MAX 5001

using namespace std;

int array[MAX];
int n;
int k;
bool okay = false;
bool verify(){ 
	for(int i = 0 ; i < k-1 ; i++) 
		if(abs(array[i]-array[i+1]) == 1) 
			return false; 
	return true; }

int main(){

	scanf("%d",&n);
	if(n == 1)
		printf("%d\n%d\n",1,1);
	else if(n == 2)
		printf("%d\n%d\n",1,1);
	else if(n == 3)
		printf("%d\n%d %d\n",2,1,3);
	else if(n == 4)
		printf("%d\n%d %d %d %d\n",4,2,4,1,3);
	else{
		printf("%d\n",n);
		for(int i = 2 ; i <= n; i+=2)
			printf("%d ",i);
		for(int i = 1; i <= n ; i+=2)
			printf("%d ",i);
	
		printf("\n");
	}

	return 0;
}
