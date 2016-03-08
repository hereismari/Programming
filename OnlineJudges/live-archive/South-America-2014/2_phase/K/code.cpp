#include <bits/stdc++.h>

#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define MAX 10000000 //TODO
#define ll long long
#define BLACK 0
#define WHITE 1
#define pb push_back
#define MOD 1000000007

using namespace std;

int n, m, x, y, pos[MAX];
bool sit[MAX];

int main() {

	while(scanf("%d %d", &n, &m) != EOF) {
		
		memset(pos, -1, sizeof pos); 
		memset(sit, false, sizeof sit);
		
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y); x--; y--;
			pos[y] = x;
			sit[x] = true;
		}
		
		int x = 0;
		int begin;
		for(int i = 0; i < 2*n; i++){	
			if(i >= n && x == 0) { begin = i-n; break; }
			if(!sit[i % n] && pos[i % n] >= 0) x++;
			else if(sit[i % n] && pos[i % n] < 0) x--;
			
			if(x < 0) x = 0;
		}
		
		x = 0;
		ll ans = 1;
		for(int i = begin; i < n + begin; i++){
			
			if(!sit[i % n]) x++;
			if(pos[i % n] < 0) { ans = (ans * x) % MOD; x--; } 
			
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}


