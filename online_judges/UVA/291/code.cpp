#include <bits/stdc++.h>

using namespace std;

#define MAX 6
#define MAX2 9

#define pb push_back

#define NOT_POSSIBLE -1
#define POSSIBLE 0

int adj[MAX][MAX];
int ans[MAX2];

void make_graph() {
    
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            adj[i][j] = NOT_POSSIBLE;

    // adding 1's edges
    adj[1][2] = adj[1][5] = adj[1][3] = POSSIBLE;
    // adding 2's edges
    adj[2][1] = adj[2][5] = adj[2][3] = POSSIBLE;
    // adding 3's edges
    adj[3][2] = adj[3][1] = adj[3][5] = adj[3][4] = POSSIBLE;
    // adding 5's edges 
    adj[5][2] = adj[5][1] = adj[5][3] = adj[5][4] = POSSIBLE;
    // adding 4's edges
    adj[4][5] = adj[4][3] =  POSSIBLE;
}

void solve(int id = 1, int cont = 1) {

    if (cont == MAX2) {
        for(int i = 0; i < MAX2; i++) printf("%d", ans[i]);
        printf("\n");
    }
    else {
        
        for(int i = 0; i < MAX; i++) {
            if(adj[id][i] == POSSIBLE) {
                
                adj[id][i] = NOT_POSSIBLE;
                adj[i][id] = NOT_POSSIBLE;
                
                ans[cont] = i;
                solve(i, cont + 1);
                
                adj[id][i] = POSSIBLE;
                adj[i][id] = POSSIBLE;
                
            }
        }

    }
}

int main() {

    make_graph();
    ans[0] = 1;
    solve();

    return 0;
}
