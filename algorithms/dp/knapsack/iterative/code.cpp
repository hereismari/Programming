#include <stdio.h>
#define MAX 100
#define max(a,b) (a > b ? a : b)

using namespace std;

int v[MAX];
int w[MAX];
int k[MAX];

int knap(int n, int weight){

	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= weight; j++){
			if(i == 0 || j == 0) k[i][j] = 0;
			else if (w[i-1] <= j)
			k[i][j] = max(v[i-1] + k[i-1][j-w[i-1]],k[i-1][j]);
			else k[i][j] = k[i-1][j];
		}

	return k[n][weight];
}




int main(){





	return 0;
}
