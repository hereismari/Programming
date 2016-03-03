#include <bits/stdc++.h>

#define MAX 21
#define ll long long int

using namespace std;

bool mat[MAX][MAX];
int n, t;

ll solve(int id, bitset<21> used) {

	if(id == n && valid(used)) return 1;
	else if(id == n) return 0;
	else if(dp[id]
	

}


int main() {

	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &mat[i][j]);
		bitset<21> used(0);
		printf("%lld\n", solve(0, used));
	}

	return 0;
}
