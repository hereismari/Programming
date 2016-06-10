#include <bits/stdc++.h> 

using namespace std; 

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

#define MAX 1000100  
#define INF 1000000

int n, m, x, y;
int mat[20][20], dist[20][20];
#define EXIT 0
#define CRYSTAL 2
#define BEGIN 3
#define COMMON 1

int move_x[] = {0, 0, -1, 1};
int move_y[] = {1, -1, 0, 0};

bool valid(int x1, int y1, int x2, int y2) {
    return (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && mat[x1][y1] != CRYSTAL && dist[x1][y1] > dist[x2][y2] + 1);
}

int main() {
 
        scanf("%d %d", &n, &m);
        queue< pii > q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                scanf("%d", &mat[i][j]);
                if(mat[i][j] == BEGIN) { q.push(mp(i,j)); dist[i][j] = 0; }
                else dist[i][j] = INF;
            }

        int ans;
        while(!q.empty()) {
            pii front = q.front(); q.pop();
            if(mat[front.F][front.S] == EXIT) { ans = dist[front.F][front.S]; break; }
            for(int i = 0; i < 4; i++) {
                x = front.F + move_x[i];
                y = front.S + move_y[i];
                if(valid(x, y, front.F, front.S)) {
                    dist[x][y] = dist[front.F][front.S] + 1;
                    q.push(mp(x,y));
                }
            }
        }
        printf("%d\n", ans);
	return 0; 
}
