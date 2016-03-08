#include<bits/stdc++.h>
#define MAX 1002

using namespace std;

int main() {

	int n,m, cont = 1;
	int a[MAX][MAX];
	while(true){
		scanf("%d %d", &n, &m);
		if(n == 0) break;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);

		int left[MAX], right[MAX], cima[MAX];
		memset(left,0,sizeof left);
		memset(right,0,sizeof right);
		memset(cima,0,sizeof cima);

		cima[0] = a[0][0];
		for(int j = 1; j < m; j++)
			cima[j] = cima[j-1] + a[0][j];

		for(int i = 1; i < n; i++){	
			
			left[0] = cima[0] + a[i][0];	
			for(int j = 1; j < m; j++)
				left[j] = max(cima[j],left[j-1]) + a[i][j];
			
			right[m-1] = cima[m-1] + a[i][m-1];
			for(int j = m-2; j >= 0; j--)
				right[j] = max(cima[j],right[j+1]) + a[i][j];

			for(int j = 0; j < m; j++){
				cima[j] = max(left[j],right[j]);
			}
		}

		printf("Teste %d\n",cont++);
		printf("%d\n\n", cima[m-1]);
	}

	return 0;
}
