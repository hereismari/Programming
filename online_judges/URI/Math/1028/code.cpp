#include <stdio.h>
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a <= b ? a : b)
using namespace std;

int n;
int f1,f2;

int mdc(int a, int b){

	int rest = a % b;
	while((rest = a % b) != 0){
		a = b;
		b = rest;
	}

	return b;
}

int main(){

	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d %d",&f1,&f2);
		printf("%d\n",mdc(max(f1,f2),min(f2,f1)));
	}

	return 0;
}
