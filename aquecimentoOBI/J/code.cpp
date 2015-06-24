#include <bits/stdc++.h>
#define MAX 100
#define MOD 257

using namespace std;

int m[MAX][MAX];
int a[MAX];

int main(){
	
	char str[MAX];
	int i = 0;
	while(scanf("\n%s",str) != EOF){
		for(int j = 0 ; j < strlen(str); j++)
			m[i][j] = str[j] - '0';
		i++;
	}

	int n = i;
	int p = strlen(str);
	
	for(int k = 0; k < n ; k++){
		for(int j = 0; j < p; j++)
		{	
			a[j] += m[k][j];
			if(k != n-1)
				a[j] *= 10;
			a[j] = a[j] % MOD;
		}
	}

	for(int k = 1; k < p-1; k++)
	{
		printf("%c",(a[0]*a[k] + a[p-1]) % MOD);
	}
	printf("\n");
	return 0;
}
