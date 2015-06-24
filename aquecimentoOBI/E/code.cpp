#include <bits/stdc++.h>
#define MAX 30000

using namespace std;

int v[MAX];
int w[MAX];

int knap2(int n, int weight){ 

	int K[MAX];
	K[0] = 0;
	int best = 0;
	for (int k = 1; k <= weight; k++) {
		for (int i = 1; i <= n; i++) {
			if (k >= w[i]) {
				best = max(K[k-w[i]] + v[i], best);
			 }
		}
		K[k] = best;
	}
   
  return K[weight];
}

int main() {

	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d %d",&w[i],&v[i]);
	}

	printf("%d\n",knap2(n,m));
	return 0;
}
