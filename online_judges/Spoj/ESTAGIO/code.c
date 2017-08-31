#include <stdio.h>

struct aluno{int id;int pont;} alunos[10000];


int main()
{
int N,i,maior,cont;

scanf("%d",&N);


cont=1;
while(N)
{
    maior=0;

    for(i=0;i<N;i++)
        {
            scanf("%d%d",&alunos[i].id,&alunos[i].pont);
            if (alunos[i].pont>maior)
                maior=alunos[i].pont;
        }
    printf("Turma %d\n",cont);
    for(i=0;i<N;i++)
        if(alunos[i].pont == maior)
            printf("%d ",alunos[i].id);

 printf("\n");
 scanf("%d",&N);
 cont++;
}
 return 0;
 }