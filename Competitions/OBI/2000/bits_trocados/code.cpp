#include <stdio.h>

int main()
{
int i,controle,num,nota50[100],nota10[100],nota5[100],nota1[100];
controle=0;
scanf("%d",&num);
for(i=0;i<100;i++)
{
      nota50[i]=nota10[i]=nota5[i]=nota1[i]=0;

}
while(num!=0)
{
while(num)
{
if (num>=50)
{
    nota50[controle]++;
    num-=50;
}
 else if (num>=10 && num<50)
{
    nota10[controle]++;
    num-=10;
}
  else  if (num>=5 && num<10)
{
    nota5[controle]++;
    num-=5;
}
  else if (num>=1 && num<5)
{
    nota1[controle]++;
    num-=1;
}

}
scanf("%d",&num);
++controle;
}
for(i=0;i<controle;i++)
printf("Teste %d\n%d %d %d %d\n\n",i+1,nota50[i],nota10[i],nota5[i],nota1[i]);
return 0;
}
