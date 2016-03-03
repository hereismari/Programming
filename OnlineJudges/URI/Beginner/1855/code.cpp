#include <bits/stdc++.h> 

#define MAX 1000 
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

int n, m, x, y;
char mat[MAX][MAX];
bool vis[MAX][MAX];
map<char, pii> dir;

bool invalid(int i, int j){
    return i < 0 || j < 0 || i > m || j > n || vis[i][j];
}

bool can(int i, int j, char d) {
//    printf("%c\n", mat[i][j]);
    if(invalid(i,j)) return false;
    else if(mat[i][j] == '*') return true;
    else {
        vis[i][j] = true;
        char direc = mat[i][j] != '.' ? mat[i][j] : d; 
        return can(i + dir[direc].F, j + dir[direc].S, direc);
    }
}

int main() {

    dir['v'] = mp(1, 0);
    dir['^'] = mp(-1, 0);
    dir['<'] = mp(0, -1);
    dir['>'] = mp(0, 1);

    scanf("%d", &n);
    scanf("%d", &m);
    memset(vis, false, sizeof vis);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("\n%c", &mat[i][j]);
    printf("%c\n", can(0,0,mat[0][0]) ? '*' : '!');
	return 0; 
}
