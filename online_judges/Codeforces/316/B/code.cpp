#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    ll n,m;
    scanf("%lld %lld",&n,&m);

    ll chance = m-1;
    ll ans = m-1;
	
    if(n - m > chance)
        ans = m+1;
    printf("%lld\n",(n == 1? 1: ans));

    return 0;
}
