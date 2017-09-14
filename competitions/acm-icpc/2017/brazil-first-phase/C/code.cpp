#include <bits/stdc++.h>

using namespace std;


long long int gcd(long long int a, long long int b) {
	if(a == 0) return b;
	return gcd(b%a, a);
}

int main() {
	
	long long int n,l;
	
	scanf(" %lld %lld", &n, &l);
	
	long long int mmc;
	
	scanf(" %lld", &mmc);
	for(int i = 0; i < n-1; i++) {
		long long int x;
		scanf(" %lld", &x);
	
		long long int tmp = gcd(mmc, x);
		mmc = mmc *(x / tmp); 
	}
	
	long long int mxi = 1;
	long long int mx = mmc;
	
	for(int i = 1; i <= l; i++) {
		long long int newgcd = gcd(mmc, i);
		long long int newmmc = mmc * (i / newgcd); 
		
		if(newmmc <= l && newmmc > mx) {
			mx = newmmc;
			mxi = i;
		}
	}
	
	printf("%lld\n", mxi);
	
	return 0;
}


