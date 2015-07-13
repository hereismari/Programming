#include <bits/stdc++.h>
#define  ll long long int
#define MAX  10000
#define MOD 1000007

using namespace std;
ll value;

ll fat(int x){
	ll res = 1;
	for(int i = 1; i <= x; i++) res = (res * i) % MOD;
	return res;
}

ll A(int x, int y) {
	ll res = fat(x);
	res /= fat(x-y);
	return res;
}

int main() {
	ll x;
	int n, k;
	scanf("%d %d",&n,&k);
	scanf("%lld",&value);

	int menores = 0;
	for(int i = 0; i < pow(2,n)-1; i++){
		scanf("%lld",&x);
		if(x < value) menores++;
	}
	
	ll answer = n;
	answer = (answer * A(pow(2,k-1) -1, menores)) % MOD;
	answer = (answer * (fat(n-pow(2,k-1))-A(pow(2,k-1),menores - pow(2,k-1) -1))*fat(n-pow(2,k))) % MOD;

	printf("%lld",answer);

	
}
