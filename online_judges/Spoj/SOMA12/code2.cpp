#include <bits/stdc++.h>
#define MAX 500100
#define ll long long int

using namespace std;

ll a[MAX];
int n;

bool binSearch(ll x) {
	
	int i = 0;
	int j = n-1;
	int m = j/2;
	while(i < j){
		if(a[m] == x) return true;
		else if(a[m] < x) i = m+1;
		else j = m;
		m = (i+j)/2;
	}

	return false;
}

int main() {

	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%lld",&a[i]);
	ll k;
	scanf("%lld",&k);

	for(int i = 0; i < n; i++){
		if(k - a[i] >= 0)
			if(binSearch(k-a[i])){
				printf("%lld %lld\n",a[i],k-a[i]); return 0;
			}
	}

	return 0;
}
