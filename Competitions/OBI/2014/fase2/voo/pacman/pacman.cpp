#include <stdio.h>
#define MAX 101
using namespace std;

int n;
char m[MAX][MAX];
int cont;
int max;

int main(){

	scanf("%d",&n);
	
	for(int i = 0 ; i <  n ; i++)
		for(int j = 0 ; j < n ; j++)
			scanf("\n%c",&m[i][j]);
	
	cont = 0;
	max = 0;
	
	for(int i = 0 ; i < n ; i++)
		if(i % 2 == 0)
			for(int j = 0 ; j < n; j++){
				if(m[i][j] == 'o')
					cont++;
				else if(m[i][j] == 'A'){
					if(cont > max)
						max = cont;
					cont = 0;}
		}
		else
		for(int j = n-1 ; j >=0; j--){
				if(m[i][j] == 'o')
					cont++;
				else if(m[i][j] == 'A'){
					if(cont > max)
						max = cont;
					cont = 0;}
		}

	if(cont > max)
		max = cont;
	
	printf("%d\n", max);

	return 0;
}
