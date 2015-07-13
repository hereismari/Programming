#include <bits/stdc++.h>
#define MAX 100
#define ll long long 

using namespace std;
  
int dist[MAX][MAX];
int memo[MAX][1 << MAX];
int x[MAX];
int y[MAX];
int nx, ny, n;
 
int solve(int index, int mask) {

    if (mask == (1 << (n + 1)) - 1)
        return dist[index][0];
    if (memo[index][mask] != -1)
        return memo[index][mask];
    memo[index][mask] = INT_MAX;
    for (int i = 0; i <= n; ++i)
        if (i != index && !(mask & (1 << i)))
            memo[index][mask] = min(memo[index][mask], solve(i, mask ^ (1 << i)) + dist[index][i]);

    return memo[index][mask];
}
 
int main() {

    int T; cin >> T;
    while (T-- != 0) {

        cin >> nx >> ny;
        cin >> x[0] >> y[0];
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> x[i] >> y[i];
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        memset(memo, -1, sizeof(memo));
        printf("The shortest path has length %d\n", solve(0, 1));
    }
	return 0;
}
