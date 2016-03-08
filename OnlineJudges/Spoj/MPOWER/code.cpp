#include <bits/stdc++.h>
#define ll long long int

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
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%lld %lld %lld",&x,&y,&m);
		printf("%lld\n",power(x,y,m));
	}

}


