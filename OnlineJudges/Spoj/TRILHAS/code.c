#include <stdio.h>
int main()
{
int vetor[101];
int trilha[1001];
int N,M,i,j,k,pont1,pont2,maior;
scanf("%d",&N);
maior=10000000;
for(i=1;i<=N;i++)
{
    pont1=0;
    pont2=0;
    scanf("%d",&M);

    for(k=1;k<=M;k++)
        scanf("%d",&trilha[k]);

        for(k=1;k<M;k++){
                if(trilha[k+1]>trilha[k])
        pont1+=trilha[k+1]-trilha[k];
        }
         for(k=M;k>1;k--){
            if(trilha[k]<trilha[k-1])
        pont2+=trilha[k-1]-trilha[k];

         }
    if(pont1<pont2)
        vetor[i]=pont1;
    else
        vetor[i]=pont2;



}
for(i=1;i<=N;i++)
{
    if(vetor[i]<maior)
    {
          pont1=i;
          maior=vetor[i];
    }

}
printf("%d",pont1);

return 0;
}