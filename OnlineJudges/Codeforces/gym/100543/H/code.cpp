#include <bits/stdc++.h>

#define range(i,n) for(int i=0; i<n; ++i)
typedef long long ll;

using namespace std;


list<int> graph[10];
vector<int> valid;

void dfs(int cur, int k=1) {
	valid.push_back(cur);
	if(k < 3) for(int adj : graph[cur%10])
		dfs(cur*10+adj, k+1);
}

int main() {
	range(i, 10) range(j, 10) if(i > 0)
		if(i%3 != 0 and j == 0 or (i-1)/3 <= (j-1)/3 and (i-1)%3 <= (j-1)%3)
			graph[i].push_back(j);
	graph[0].push_back(0);
	range(i, 10) dfs(i);
	
	int n;
	scanf("%d", &n);
	
	while(n--) {
		int x, ans=0;
		scanf("%d", &x);
		for(int y : valid)
			if(abs(x-y) < abs(x-ans))
				ans = y;
		printf("%d\n", ans);
	}
	
	return 0;
}
