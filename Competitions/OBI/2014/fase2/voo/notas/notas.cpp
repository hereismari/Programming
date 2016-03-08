#include <stdio.h>

#define MAX 201

int n;
int notas[MAX];
int max_num;
int x;

using namespace std;

int main(){

	for(int i = 0 ; i < MAX ; i++)
		notas[i] = 0;

	scanf("%d",&n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d",&x);
		notas[x]++;}
	
	max_num = 0;
	for(int i = 1 ; i < MAX ; i++)
		if(notas[i] >= notas[max_num])
			max_num = i;
	
	printf("%d\n",max_num);

	return 0;
}
