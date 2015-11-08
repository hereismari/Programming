#include <bits/stdc++.h>

using namespace std;

int main() {

	int n,i,j,x;
	char k;
	int pares_D[61];
	int pares_E[61];
	

	while(1) {
		
		if (scanf("%d",&n) == EOF) break;
		for(i=30;i<=61;i++) { pares_D[i] = 0; pares_E[i] = 0; }
	
		for(i=0;i<n;i++) {
			scanf("%d %c",&j,&k);
			if (k =='E')
				++pares_E[j];
			else if(k == 'D')
				++pares_D[j];	
		}

		x = 0;
		for(i=30;i<=60;i++)
		{
			if (pares_D[i] < pares_E[i])
				x+=pares_D[i];
			else
				x+=pares_E[i];	
		}
		printf("%d\n",x);
	
	}


	return 0;
}

