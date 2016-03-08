#include <stdio.h>
#define MAX 10001
#define max(a,b,c) (a > b && a > c)
#define min(a,b,c) (a < b && a < c)

using namespace std;

int n;
int input[MAX];

int main(){

	while(1){
		
		scanf("%d",&n);
		if(n == 0)
			break;
		
		for(int i = 0 ; i < n ; i++)
			scanf("%d",&input[i]);

		int cont = 0;
		if(max(input[0],input[1], input[n-1])) cont++;
		if(min(input[0],input[1],input[n-1])) cont++;
	
		if(max(input[n-1],input[n-2], input[0])) cont++;
		if(min(input[n-1],input[n-2],input[0])) cont++;
		
		for(int i = 1 ; i < n-1 ; i++)
			if(max(input[i],input[i-1],input[i+1]) || min(input[i],input[i-1],input[i+1])) cont++;

	printf("%d\n",cont);
	
	}

	return 0;
}
