#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n, k;
	scanf("%d", &n);
	scanf(" %d", &k);
	
	vector<float> v;
	for(int i = 0; i < n; i++) {
		float x;
		scanf(" %f", &x);
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	
	int ans = 0;
	for(int i = n-1; i >= 0; i--) {
		if(i + 1 <= n && v[i] == v[i+1]) {
			ans++;
		}
		else if(ans >= k) break;
		else ans++; 
	}
	
	printf("%d\n", ans);
	
	return 0;
}
