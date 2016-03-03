#include <bits/stdc++.h> 

#define MAX 1000100 
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;
int a[MAX];

int main() {
 
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; i++)
		scanf("%d",&a[i]);

	bool dp[n+1];
	memset(dp,false,sizeof dp);

	dp[0] = true;
	for(int i = 0; i < m; i++)
		for(int j = n; j >= 0; j--){
			if(j-a[i] >= 0 && dp[j-a[i]])
				dp[j] = true;
		}

//	for(int i= 0; i <= n; i++)
//		printf("%d ",dp[i]);
	
	printf("%c\n",dp[n]?'S':'N');
	return 0; 
}
