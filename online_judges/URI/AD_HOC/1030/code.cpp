#include <stdio.h>

using namespace std;


int f(int j, int k){

	if (j == 1)
		return 1;
	else
		return (k-1 + f(j-1,k))%j + 1;
}

int main(){

	int n,j,k;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d %d",&j,&k);
		printf("%d\n",f(j,k));
	}

}
