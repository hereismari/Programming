#include <cstring>
#include <cstdio>
#define MAXR 110
#define MAXA 10100

using namespace std;

int a[MAXR];
int dp[MAXR][MAXA];
int n, k,x,y;
bool flag;

bool answer(int i, int j){

	if(flag) return true;
	if(dp[i][j] >= 0) return dp[i][j];
	if(i > n) return dp[i][j] = false;
	if(j == k) return flag = dp[i][j] = true;
	if(j > k) return dp[i][j] = false;
	if(answer(i+1,j) || answer(i+1,j+a[i+1])) return flag = dp[i][j] = true;

	return dp[n][k]=false;
}


int main() {

	while(scanf("%d %d",&n,&k) != EOF) {

		memset(a,0,sizeof(a));
		memset(dp,-1,sizeof(dp));
		flag = false;
		for(int i = 0; i < k; i++){
			scanf("%d %d",&x,&y);
			a[x]++; a[y]++;
		}
		
		printf("%c\n",answer(0,0)?'S':'N');
	}

	return 0;
}
