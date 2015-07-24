#include <bits/stdc++.h> 

#define MAX 1000 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;
int v[MAX], w[MAX];
int cap, resistance;

bool knap(){

	int dp[MAX][MAX];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= cap; j++){
			if(i == 0 || j == 0) dp[i][j] = 0; 
			else if(w[i] <= j)
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + v[i]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}	
//	printf("%d\n",dp[n][cap]);
	return dp[n][cap] >= resistance;
}

int main() {
 
	scanf("%d",&m);
	while(m--){

		scanf("%d",&n);
		for(int i = 1; i <= n; i++) scanf("%d %d",&v[i],&w[i]);
		scanf("%d",&cap);
		scanf("%d",&resistance);
		printf("%s\n",knap()?"Missao completada com sucesso":"Falha na missao");
	}

	return 0; 
}
