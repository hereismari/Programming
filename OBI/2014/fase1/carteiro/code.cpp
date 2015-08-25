#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int main() {

	
	int n,m,cont,index;
	int i;
	long long x;
	map<long long int,int> casas;
	
	
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){
		scanf("%lld",&x);
		casas[x] = i;
		}
	cont = 0;
	index = 0;
	for(i=0;i<m;i++)
	{
		scanf("%lld",&x);
		cont += abs(casas[x] - index);
		index = casas[x];
	}
	printf("%d",cont);
	return 0;
}

