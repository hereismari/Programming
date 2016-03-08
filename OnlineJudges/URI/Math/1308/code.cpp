#include <stdio.h>
#include <math.h>
#define ll long long int

using namespace std;

ll answer(ll x){

	ll delta = sqrt(1.0 + 8.0*x);
	ll ans =  (delta - 1)/2;
	return ans;
}

int main(){

	int n;
	ll x;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%lld",&x);
		printf("%lld\n",answer(x));
	}

	return 0;
}

