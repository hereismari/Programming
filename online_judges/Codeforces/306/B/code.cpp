#include <bits/stdc++.h>
#define INF 1100000
#define ll long long int
using namespace std;

int main(){

	int n,l,r,x;
	scanf("%d %d %d %d",&n,&l,&r,&x);
	
	int y;
	int values[17];
	for(int i = 0; i < n; i++){
		scanf("%d",&y);
		values[i] = y;
	}

	ll cont = 0;
	for(int mask = 0; mask != (1<<n); mask++){
		bitset<17> foo(mask);
		
		ll sum = 0;
		ll minimum = 1000002;
		ll maximum = 0;
		for(int i = 0; i < n; i++){
			if(foo.test(i))
			{
				sum += values[i];
				if(values[i] < minimum)
					minimum = values[i];
				if(values[i] > maximum)
					maximum = values[i];
			}
		}
		
		if(sum >= l && sum <= r && maximum - minimum >= x)
			cont += 1;

	}	

	printf("%lld\n",cont);
	return 0;
}
