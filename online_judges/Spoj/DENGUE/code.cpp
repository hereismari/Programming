#include <bits/stdc++.h>
#define INF 1000000
#define MAX 101

using namespace std;

int dist[MAX][MAX];
int n, x, y;

void calculateDist() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][k] + dist[k][j],dist[i][j]);
}

int main() {

    int teste = 1;
    while(true) {
        scanf("%d",&n);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                dist[i][j] = (i == j) ? 0 : INF;

        if(n == 0) break;
        for(int i = 0; i < n-1; i++){
            scanf("%d %d",&x,&y);
            dist[x][y] = dist[y][x] = 1;
        }

        calculateDist();
        int ans = INT_MAX;
        int index = 1;
        for(int i = 1; i <= n; i++){
            int max_dist = 0;
            for(int j = 1; j <= n; j++){
                max_dist = max(dist[i][j], max_dist);
            }
            if(max_dist < ans){
                ans = max_dist;
                index = i;
            }
        }
        printf("Teste %d\n%d\n\n",teste++,index);
    }

    return 0;
}