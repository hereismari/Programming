#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int X;
	
    scanf("%d",&X);
    int maior = X; //guarda maior valor, até agora é X
    while(X > 0){
        scanf("%d",&X); //lembrar do & no scanf
    	if(X > maior) 
    		maior = X; // se esse valor for maior que o que nós temos, atualizamos
    }
    
    
    printf("%d\n",maior);
    return 0;
}

