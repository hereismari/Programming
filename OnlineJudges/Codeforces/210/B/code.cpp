#include<bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    
	scanf("%d %d", &n, &k);	
	
	int a[n+1];    
	for(int i=1; i<=n; i++) a[i] = i;
    
    if(n == k) { puts("-1"); return 0; }
    for(int i= n - k; i > 1; i -= 2) swap(a[i], a[i-1]);
    
	for(int i=1; i<=n; i++) printf("%d ", a[i]);
    return 0;
}
