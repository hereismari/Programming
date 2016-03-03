#include <stdio.h>
#define MAX 41

using namespace std;

int fib[MAX];

int init_fib(int i){

	if(fib[i] != -1) return fib[i];
	fib[i] = init_fib(i-1) + init_fib(i-2);
	return fib[i];
}

int main(){
	int n;
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 2;	
	for(int i = 3; i <= 40; i++) fib[i] = -1;
	init_fib(MAX-1);

	while(1){
		scanf("%d",&n);
		if(n == 0) break;
		printf("%d\n",fib[n]);
	}
	return 0;
}
