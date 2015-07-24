#include <bits/stdc++.h>

using namespace std;

int main() {
	int cont = 1;
	while(true) {
		int x,y,n;
		scanf("%d %d %d",&x,&y,&n);
		if(x == 0) break;		
		int a[n], sum = 0;
		for(int i = 0; i < n; i++) {scanf("%d",&a[i]); sum += a[i]; }

		int V1 = (x+y+sum)/2 - x;
		bool ans[sum+1] = {false};
		ans[0] = true;
		for(int i = 0; i < n; i++){
			for(int j = V1; j >= 0; j--){
				if(ans[j])
					ans[j + a[i]] = true;
			}
		}
	
//		for(int i = 0; i <= V1; i++)
	//			printf("%d ",ans[i]);

		printf("Teste %d\n",cont++);
		if(ans[V1] && (x+y+sum) % 2 == 0) printf("S\n\n"); else printf("N\n\n");
	}
	return 0;
}
