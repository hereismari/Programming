#include <stdio.h>
#include <string.h>
using namespace std;

int main() {

	int n, m, x;
	bool a[10000+1];
	while(scanf("%d %d",&n,&m) != EOF){
		memset(a, false, sizeof a);
		for(int i = 0; i < m; i++){
			scanf("%d",&x);
			a[x] = true;
		}
		if(n == m) printf("*\n");
		else{
			for(int i = 1; i <= n; i++){
				if(!a[i]) printf("%d ",i);
			} 
			printf("\n");
		}
	}

	return 0;
}
