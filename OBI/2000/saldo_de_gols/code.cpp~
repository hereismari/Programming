#include <stdio.h>

int main() {

	int maior_atual,maior_geral,xtemp,xfinal,xinicial,vetor[10000];
	int i,n,mais,menos,cont=0;
	scanf("%d",&n);
	while(n!=0) {
		cont++;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&mais,&menos);
			vetor[i]=mais-menos;
		}
		maior_atual=0;
		maior_geral=-1;
		xtemp=1;
		xfinal=1;
		xinicial=1;
		for(i=1;i<=n;i++) {
			maior_atual+=vetor[i];
			if(maior_atual<0)
			{
			    maior_atual=0;
			    xtemp=i+1;
			}
			if(maior_atual>=maior_geral)
			{
			    maior_geral=maior_atual;
			    xfinal=i;
			    xinicial=xtemp;
			}

		}
		printf("Teste %d\n",cont);
		if(maior_geral<=0)
		    printf("nenhum\n\n");
		else
		    printf("%d %d\n\n",xinicial,xfinal);
		scanf("%d",&n);
	}

	return 0;

}
