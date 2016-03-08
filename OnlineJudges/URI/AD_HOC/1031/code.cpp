#include <stdio.h>

using namespace std;

int f(int j, int k){
	if (j == 1)
		return 1;
	else
		return ((k-1 + f(j-1,k)) % j) + 1;
}

int main(){

	int n,j,k,m;
	int i;
	while(1) {
		scanf("%d",&n);
		if (n == 0) break;
		i = 1;
	while(f(n-1,i) + 1 != 13){
//		printf("%d %d\n",i,f(n,i));
		i++;
		}
		printf("%d\n",i);
	}

	return 0;
}
