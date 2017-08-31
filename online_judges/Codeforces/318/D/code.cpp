#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	scanf("%d",&n);
	
	int a[n];
	int l[n], r[n];
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	
	int dist = 1;
	for(int i = 0; i < n; i++) {dist = min(dist,a[i]); l[i] = dist++;}
	
	dist = 1;
	for(int i = n-1; i >= 0; i--) {dist = min(dist,a[i]); r[i] = dist++;}
	
	int ans = 0;
	for(int i = 0; i < n; i++) 
		ans = max(ans,min(l[i], r[i]));

	printf("%d\n", ans);
	return 0;
}
