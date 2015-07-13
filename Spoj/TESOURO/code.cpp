#include <bits/stdc++.h>

using namespace std;

int main() {
	int cont = 1;
	while(true) {
		int x,y,n;
		scanf("%d %d %d",&x,&y,&n);
		if(x == 0) break;		
		int a[n];
		for(int i = 0; i < n; i++) scanf("%d",&a[i]);
		sort(a,a+n);	

		for(int i = n-1; i >= 0; i--){
			if(x > y) swap(x,y);
			x += a[i];
		}

		printf("Teste %d\n",cont++);
		if(x == y) printf("S\n\n"); else printf("N\n\n");
	}
	return 0;
}
