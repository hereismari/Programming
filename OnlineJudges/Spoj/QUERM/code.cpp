#include <stdio.h>

int main() {

    int controle, i, respostas[100],aluno,x;
    scanf("%d", &controle);
    x = 0;

    while(controle) {
        for(i = 1; i <= controle; i++) {
            scanf("%d",&aluno);
            if(aluno == i) respostas[x] = aluno;
    }
    
    x++;
    scanf("%d", &controle);
    
    }

    for(i=0;i<x;i++) printf("Teste %d\n%d\n\n",i+1,respostas[i]);
    return 0;
} 
