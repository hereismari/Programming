#include <bits/stdc++.h>
#define ll long long int
#define MOD 10000007

using namespace std;

ll power(ll x, ll y, ll m) {
	
	ll result = 1;
	while( y > 0 ){
		
		if(y % 2 == 1)
			result = (result * x) % m;
		
		y = y/2;
		x = (x * x) % m;
	}

	return result;
}

int main() {

	ll x, y, m;
	int n;
	while(scanf("%lld %lld",&x,&y)){
		if(x == 0) break;
		ll answer = (2*power(x-1,y,MOD) + 2*(power(x-1,x-1,MOD)) + power(x,y,MOD) + power(x,x,MOD)) % MOD;
		printf("%lld\n",answer);
	}

}


