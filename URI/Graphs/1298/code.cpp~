#include <bits/stdc++.h> 

#define MAX 610
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std;

char c;
bool valid[MAX][MAX][4];
bool visited[MAX][MAX];
int ans, n;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

void bfs(int i, int j) {

    queue<pii> q; 
    q.push(mp(i,j));
    visited[i][j] = true;
                     
    while(!q.empty()) {
        pii p = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int x = p.F + di[i];
            int y = p.S + dj[i];

            if(x >=0 && x <2*n && y >=0 && y <2*n+1)
                if(!visited[x][y] && valid[p.F][p.S][i]){
                    visited[x][y] = true;
                    q.push(mp(x,y));    
                }
        }
    }
}

int main() {
   
    while(scanf("%d", &n) != EOF) {
         
        memset(valid , true, sizeof valid);
        memset(visited, false, sizeof visited);
         
        for(int i = 0; i < 2*n-1; i++) {
            for(int j = 0; j < n; j++) {

                int x = i;
                int y = 2*j + (i & 1);

                scanf("\n%c", &c);
 
                if(c =='H'){
                    valid[x][y][0] = valid[x][y+1][0] = false;
            	    valid[x+1][y][1] = valid[x+1][y+1][1] = false;
                }
		else{
                    valid[x][y][2] = valid[x][y+1][3] = false;
                    valid[x+1][y][2] = valid[x+1][y+1][3] = false;
                }                 
            }   
        }
        
	ans = -1;
	for(int i = 0; i < 2*n; i++) 
	    for(int j = 0; j < 2*n+1; j++) 
		if(!visited[i][j]) { ans++; bfs(i,j); }
   
        cout << ans <<endl;
    }
      
    return 0;
}
