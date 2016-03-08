#include <stdio.h>

int main()
{
char nome1[11],nome2[11];
int n,i,num1,num2,soma;
int teste = 1;
scanf("%d",&n);
while(n!=0){
scanf("%s%s",&nome1,&nome2);
printf("Teste %d\n",teste++);
for(i=0;i<n;i++)
{
    scanf("%d%d",&num1,&num2);
    soma =num1+num2;
    soma%2==0?printf("%s\n",nome1):printf("%s\n",nome2);
}
printf("\n");
scanf("%d",&n);
}
return 0;
}
