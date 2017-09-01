#include <stdio.h>

#define MAX 501

using namespace std;

int m[MAX][MAX];
int checa(int n, int p, int k, int l){
	
	for(int i = n; i < k ; i++)
		for(int j = 0 ; j <= p ; j++)
			if(m[i][j] != 0 && (i != n || j != p))
				return false;

	return true;

}

int k,l;
int cont;
bool at = false;
bool can = true;
int main(){

	scanf("%d %d",&k,&l);	
	for(int i = 0 ; i < k ; i++)
		for(int j = 0 ;j < l; j++)
			scanf("%d",&m[i][j]);
	at = false;
	can = true;	
	for(int i = 0 ; i < k ; i++){
		cont = 0;
		for(int j = 0 ; j < l ; j++)
		{
//			printf("%d ",m[i][j]);
			if(!can)
				break;
			else if(at){
				if(m[i][j] != 0){
					can = false;
					break;}}
			else if(m[i][j] != 0){
//				printf("%d\n",m[i][j]);
				can = checa(i,j,k,l);
				cont = 1;
				break;
			}
		}	
		if(cont == 0)
			at = true;
	}

	printf("%c\n",can?'S':'N');
	return 0;
}
