#include <iostream>
#include <math.h>
#include<stdio.h>
#include <stdlib.h>   
#define MAX 100000
using namespace std;

long long int i,x,n,cont;
long long int l[MAX+1];

int main() {
	while(1){
		
		scanf("%lld",&n);
		
		if (n == 0)
			break;
		
		for(i =0; i< n; i++)
			scanf("%lld",&l[i]);
		x = 0;
		cont = 0;
		for(i=1;i<n;i++)
		{
			x = l[i-1];
			l[i] = l[i-1] + l[i];
			
			if(x < 0)
				x = x*-1;
			
			cont += x;
		}
		
		printf("%lld\n",cont);

	}
	return 0;
}

