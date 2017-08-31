#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
	
	ll x, y, n;
	scanf("%lld %lld %lld", &x, &y, &n);
	
	ll x1, y1, t1;
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		
		scanf("%lld %lld %lld", &x1, &y1, &t1);
		
		ll aux_x = (x1 - x) * (x1 - x);
		ll aux_y = (y1 - y) * (y1 - y);
		
		if(aux_x + aux_y < t1*t1) ans.push_back(i+1); 
		
	}
	
	if(ans.size() == 0) printf("-1\n");
	else {
		printf("%d", ans[0]);
		for(int i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
		printf("\n");
	}
	
	return 0;
	
}
