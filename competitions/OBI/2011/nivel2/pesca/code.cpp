#include <stdio.h>
#define MAX 1000

using namespace std;

int m[MAX][MAX] = {0};
int n;
int x1,x2,y1,y2;

void preenche(int a,int b, int c, int d){
	for(int i = c ; i <= d; i++)
		for(int j = a; j <= b ; j++)
			m[i][j] = 1;
}

int answer(){
	int cont = 0;
	for(int i = 0 ; i < MAX; i++)
		for(int j = 0 ; j < MAX; j++)
			cont += m[i][j];
	return cont;
}

int main(){
	int cont1 = 0;
	scanf("%d",&n);
	for(int i = 0 ; i < n;i++){
		scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
		preenche(x1,x2-1,y1,y2-1);
	}

	printf("%d\n", answer());
	return 0;
}
