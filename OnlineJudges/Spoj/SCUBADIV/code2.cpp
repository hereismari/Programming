#include <bin/stdc++.h>
#define MAX 1000
using namespace std;

int n,oxi,nitro;
struct cylinder{
	int o, n, w;
	cylinder(int o, int n, int w) {
		this->o=o;
		this->n=n;
		this->w=w;
	}
};
cylinder c[MAX];
int dp[MAX][MAX][MAX];

int knap() {

	memset(dp,0,sizeof dp);
	for(int i = 0 ; i <= k; i++){
		for(int j = 0; j <= oxi; j++)
			for(int l = 0; j <= nitro;l ++){
				if(i == 0 || j == 0 || k == 0) dp[i][j][l] = 0;
				if(c[i].o >= oxi && c[i].n >= nitro){
					dp[i][j][l] = min(dp[i-1][j][l],c[i].w + dp[i-1][j-c[i].o][l-c[i].n]);
				}
				if(c[i].o >= oxi){
					dp[i][j][l] = min(dp[i-1][j][l],c[i].w + dp[i-1][j-c[i].o][l]);
				}
				if(c[i].n >= nitro) {
					dp[i][j][l] = min(dp[i-1][j][l],c[i].w + dp[i-1][j][l-c[i].n]);
				}
				else {
					dp[i][j][l] = dp[i-1][j][l];
				}
			}
	}

	return dp[k][oxi][nitro];
}


int main() {
	
	scanf("%d",&n);
	for(int i = 0 ; i < n; i ++) {
		scanf("%d %d",&oxi,&nitro);
		scanf("%d",&k);
		for(int j = 1 ; j <= k; j++) {
			scanf("%d %d %d",&x,&y,&z);
			o[j] = cylinder(x,y,z);
		}
		printf("%d\n",knap());
	}

	return 0;
}
