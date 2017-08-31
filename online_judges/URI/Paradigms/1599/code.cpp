#include <bits/stdc++.h>

using namespace std;

int main() {
	
	
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF) {
	
		int mat[n+1][m+1];
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		
		bool ans = false;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				bool flag = true;
				for(int k = -1; k <= 1; k++) {
					for(int l = -1; l <= 1; l++) {
						int ii = i + k;
						int jj = j + l;

						if(ii >= 0 && ii < n && jj >= 0 && jj < m) {
							if((ii != i || jj != j) && mat[i][j] <= mat[ii][jj])
								flag = false;
						}
					}
				}
				if(flag) { ans = true; printf("%d %d\n", i+1, j+1); }
			}
		}
		
		if(!ans) printf("-1\n");
		printf("\n");
	}
	return 0;
}
