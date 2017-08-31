#include <stdio.h>

int main(){

	int i,N;
	int a,b;
	int aldo,beto,cont;
	
	cont = 1;
	while(1){
	aldo = beto = 0;
	scanf("%d",&N);
	if(N==0)
	   break;
	for(i=0;i<N;i++){
	scanf("%d %d",&a,&b);
	aldo+=a;
	beto+=b;
	}
	printf("Teste %d\n",cont++);
	if(aldo>beto)
		printf("Aldo\n\n");
	else
		printf("Beto\n\n");
	}
	return 0;
}
