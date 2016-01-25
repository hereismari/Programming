#include <bits/stdc++.h>
#define MAX 500100
#define ll long long int

using namespace std;

ll a[MAX];
int n;

int main() {

	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%lld",&a[i]);
	ll k;
	scanf("%lld",&k);

    sort(a, a + n);
    int ans1, ans2;
	for(int i = 0, j = n-1; i < j;){
		if(a[i] + a[j] > k) j--;
        else if(a[i] + a[j] < k) i++;
        else { ans1 = a[i]; ans2 = a[j]; break; }
	}

    printf("%d %d\n", ans1, ans2);

	return 0;
}
