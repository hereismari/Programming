#include <stdio.h>
#define MAX 10001

using namespace std;

int a,c;
int input[MAX];
int cont;

int main(){

	while(1){

		scanf("%d %d",&a,&c);
		if(a == 0 && c == 0) break;

		for(int i = 0 ; i < c ; i++)
			scanf("%d",&input[i]);
		
		cont = a - input[0];
		for(int i = 1; i < c; i++){
			if(input[i] < input[i-1])
				cont += input[i-1] - input[i];
		}
	

		printf("%d\n",cont);
	}	

	return 0;
}
