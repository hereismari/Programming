#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a * (b/gcd(a,b))); }

int main() {

	int n;
	scanf("%d",&n);

	int a[n];
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);

	int ans = a[0];
	for(int i = 1; i < n; i++) ans = gcd(ans,a[i]);

	while(ans % 2 == 0) ans /= 2;
	while(ans % 3 == 0) ans /= 3;
	
	int can = true;
	for(int i = 0; i < n; i++) {
		int quant_2 = 1, quant_3 = 1;
		while(a[i] % (2 * quant_2) == 0) quant_2 *= 2;
		while(a[i] % (3 * quant_3) == 0) quant_3 *= 3;
		if(ans * quant_3 * quant_2 != a[i]) can = false;
	}

	printf("%s\n", can ? "Yes" : "No" );
	
	return 0;
}
