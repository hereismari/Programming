#include <stdio.h>
#include <math.h>
#define MAX 100000000
#define ll long long int
using namespace std;

int main(){

	ll n;
	ll cont = 0;
	while(1){
		scanf("%lld",&n);
		
		ll low = 0, high = MAX;
		while(low < high){
			ll mid = (low+high)/2;
			if(mid*(mid - 3) >= n * 2) 
				high = mid;
			else
				low = mid + 1;
		}
	
		printf("Case %lld: %lld\n",++cont,low);
	}

	return 0;
}

