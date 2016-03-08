#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

	int n,m;
	scanf("%d %d",&n,&m);

	ll answer = 0;
	for(int i = 1; i <= m; i++){
		answer += max(0,min(m,n-i-1) - max(1,n-i-m)+1);
	}

	printf("%lld\n",answer);
	return 0;
}
