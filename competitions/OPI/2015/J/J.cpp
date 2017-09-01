#include <cstdio>
using namespace std;

#define range(i, n) for(int i=0; i<n; i++)
#define N 10000+1

int dp[400];
bool primo[N];

int init() {
    range(i, N) primo[i] = true;
    primo[0] = primo[1] = false;

    for(int i=0; i*i<N; i++) if(primo[i])
        for(int j=i*i; j<N; j+=i)
            primo[j] = false;
}

int get(int x) {
    if(x == 1) return true;
    int y = 0;
    while(x > 0) y += (x%10)*(x%10), x/=10;
    if(dp[y] != -1) return dp[y];
    dp[y] = false;
    return dp[y] = get(y);
}

int run() {
    int t, x;
    scanf("%d %d", &t, &x);
    printf("%d %d ", t, x);
    if(not primo[x]) printf("NO");
    else printf(get(x)? "YES" : "NO");
    printf("\n");
}

int main()
{
    init();
    range(i, 400) dp[i] = -1;

    int n;
    scanf("%d", &n);
    while(n--) run();
    return 0;
}
