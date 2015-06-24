#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int main() {
	int n,p;
	scanf("%d %d",&n,&p);
	if ( p > int(ceil((n*n)/2.0))) printf("NO\n");
	else {
		printf("YES\n");
		int cont = 0;
		for(int i = 0 ; i < n; i++)
		{
			for(int j = 0; j < n; j++){
				
				if(((i % 2 == 0 && j % 2 == 0) || ( i % 2 == 1 && j % 2 == 1) )  && cont < p) { printf("L"); cont++; }
				else printf("S");

			}

			printf("\n");

		}


	}

	return 0;
}
