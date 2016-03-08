#include <bits/stdc++.h>
#define MAX 100
using namespace std;

char m[MAX][MAX];

int isFace(int x, int y){

	bool face[4] = {false};
	char word[] = {'f','a','c','e'};
	for(int i = x; i <= x + 1; i++)
		for(int j = y; j <= y + 1; j++){
			for(int k = 0; k < 4; k++)
				if(m[i][j] == word[k]){
					face[k] = true;
					break;
				}
		}

	for(int i = 0 ; i < 4; i++)
		if(!face[i])
			return 0;

	return 1;
}

int main() {

	int n,p;
	scanf("%d %d",&n,&p);
	memset(m,'x',sizeof(m));
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < p  ; j++)
			scanf("\n%c",&m[i][j]);

	int cont = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < p  ; j++)
			cont += isFace(i,j);	

	printf("%d\n",cont);

	return 0;
}
