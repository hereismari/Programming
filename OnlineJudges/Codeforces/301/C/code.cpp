#include <bits/stdc++.h>
#define MAX 550

using namespace std;

int X[4] = {0,0,-1,1};
int Y[4] = {1,-1,0,0};
int x_1, y_1, x, y;
char m[MAX][MAX];
bool can;
int n, l;
bool visited[MAX][MAX];

bool valid(int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < l);
}

int possible(int x, int y){
    int cont = 0;
    for(int k = 0; k < 4; k++){
        int i = x + X[k], j = y + Y[k];
        if(valid(i,j) && m[i][j] == '.') cont++;
    }
    return cont;
}

void dfs(int x, int y) {
    if(!valid(x,y) || m[x][y] == 'X' || visited[x][y]) return;
    visited[x][y] = true;
    if(x == x_1 && y == y_1) can = true;
    for(int k = 0; k < 4; k++) dfs(x + X[k], y + Y[k]);
}

int main() {
    
    scanf("%d %d",&n, &l);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < l; j++){
            scanf("\n%c",&m[i][j]);
        }
    }

    scanf("%d %d %d %d",&x,&y,&x_1,&y_1);
    int cont = possible(x,y);
    can = false; dfs(x,y);
    if (can && ((m[x_1][y_1] == 'X' && cont >= 1) || cont > 1))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
