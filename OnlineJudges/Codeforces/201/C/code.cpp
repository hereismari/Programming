#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y){
	if(y == 0) return x; else return gcd(y, x % y);
}

int main() {
	
	int n;
	scanf("%d\n",&n);

	int x;
	int maxV = 0;
	int div = 0;	
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&x);

		maxV = max(x,maxV);
		div = gcd(x,div);

	}

	int answer = maxV/div - n;

	if(answer % 2)
		printf("Alice\n");
	else
		printf("Bob\n");

	return 0;
}
