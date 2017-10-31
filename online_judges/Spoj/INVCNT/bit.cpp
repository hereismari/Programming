#include <bits/stdc++.h>
#define MAX 10000010
#define ll long long int

using namespace std;

ll a[MAX], n, k;
ll aux[MAX];

void update(ll x) {
    while(x < MAX) {
        a[x] += 1;
        x += (x & -x);
    }
}

ll query(ll x) {
    ll res = 0;
    while(x > 0) {
        res += a[x];
        x -= (x & -x);
    }
    return res;
}

int main() {

  int x;
	scanf("%lld\n",&n);
	
	for(int i = 0 ; i < n ; i++){
    
    memset(a, 0, sizeof a);
    
    scanf("%lld", &k);
    for(int j = 0; j < k; j++) scanf("%lld", &aux[j]);
    
    ll ans = 0;
	  
	  for(int j = k-1; j >=0; j--){
      ans += query(aux[j]-1);
      update(aux[j]);
    }

      printf("%lld\n",ans);
  }
	return 0;
}
