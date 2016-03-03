#include <stdio.h>
#include <map>
#include <math.h>
#include <stdlib.h>
using namespace std;

int n,m;
map<int, int> casas;
int x;
int pos,cont;
int main(){

	scanf("%d %d",&n,&m);
	
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d",&x);
		if(i == 0)
			pos = x;

		casas[x] = i;
	}

	cont = 0;
	for(int i = 0 ; i < m ; i++)
	{	
		scanf("%d",&x);
		cont += abs(casas[x] - casas[pos]);
		pos = x;
	}

	printf("%d\n",cont);

	return 0;
}
