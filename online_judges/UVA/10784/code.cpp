#include <stdio.h>
#include <math.h>
#define ll long long int
using namespace std;

int main(){

	ll n;
	ll cont = 0;
	while(1){
		scanf("%lld",&n);
		if(n == 0) break;
		bool ready = false;
		double d1;
		double delta = 9  + (8 * n)*1.0;
		d1 = (3.0 + sqrt(delta))/2.0;
		ll d2 = d1;
		if(d2 != d1) d2++ ;
	
		printf("Case %lld: %lld\n",++cont,d2);
	}

	return 0;
}

