#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y;

int main() {
 
    while(scanf("%d", &n) != EOF){
        int a[n];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);

        int dp[5001];
        int counter[5001];
        
        memset(counter, 0, sizeof counter);
        memset(dp, 0, sizeof dp);
        
        for(int i = 0; i < n; i++)
            for(int j = 1; j < n; j++) counter[abs(a[i] - a[j])]++;
        
        for(int i = 1; i < 5001; i++) counter[i] = counter[i] + counter[i-1];

        for(int k = 2; k < 5001; k++) {
            for(int j = i; j + j < k; j++)
                ans += counter[
        }

    }

	return 0; 
}
