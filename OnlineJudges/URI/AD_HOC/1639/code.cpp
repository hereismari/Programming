#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int ans;
bool visited[MAX];
void dfs(int n) {
    if(!visited[n]){
        visited[n] = true;
        n = n*n;
        n /= 100;
        n %= 10000;
        ans++;
        dfs(n);
    }
}


int main() {

    int n;
    while(true) {
        scanf("%d" ,&n);
        if (n == 0) break;
        ans = 0;
        memset(visited, false, sizeof visited);
        dfs(n);
        printf("%d\n",ans);
    }

    return 0;
}
