#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, x;
    scanf("%d",&n);
	int a[n+1];

	for(int i = 0; i <n; i++) {
		scanf("%d", &x);
        a[x] = i;
    }
	
    int ans = 0, aux = 1;
	for(int i = 2; i <= n; i++) {
	    if(a[i] > a[i-1]) aux += 1;
        else aux = 1;
        ans = max(ans, aux);
    }

    if(n == 1) ans = 1;
    cout << (n - ans) << endl;

	return 0;
}
