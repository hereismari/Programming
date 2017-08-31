#include <bits/stdc++.h> 

#define MAX 1000100 
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

int n, m, k;
int x, y, dir_y;

void solve(int num) {

    printf("%d", num);
    
    while(num > 0) {
        while(y <= m && y >= 1 && num--) { 
            printf(" %d %d", x, y); 
            y += dir_y;
        }
        if(y < 1 || y > m) { x++; dir_y = -1*dir_y; }
        if(y < 1) y++;
        if(y > m) y--;
    }

    printf("\n");
}

int main() {
 
    scanf("%d %d %d", &n, &m, &k);

    dir_y = 1;
    x = y = 1;

    for(int i = 0; i < k-1; i++) solve(2);
    solve(m*n - 2*(k-1));

	return 0; 
}
