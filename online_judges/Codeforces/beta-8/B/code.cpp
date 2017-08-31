#include <bits/stdc++.h> 

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
 
#define MAX 1100 
#define INF 100000000
using namespace std; 

int n, m, x, y;

struct my_pair {
    
    int first, second;
    my_pair(int f=0, int s=0) {
        first = f; second = s;
    }

    bool operator == (const my_pair &other) {
        return this->F == other.F && this->S == other.S;
    }

    my_pair operator + (const my_pair &other) const {
        return my_pair(this->F + other.F, this->S + other.S);
    }

    my_pair minFirst(my_pair p1, my_pair p2) {
        if(p1.F < p2.F) return p1;
        else return p2;
    }

    my_pair minSecond(my_pair p1, my_pair p2) {
        if(p1.S < p2.S) return p1;
        else return p2;
    }
    
    my_pair min(my_pair option1, my_pair option2, bool first) {
        return first ? minFirst(option1, option2) : minSecond(option1, option2);
    }

};

my_pair mat[MAX][MAX];
my_pair dp[MAX][MAX];
char par[MAX][MAX][2];

my_pair fact2and5(int x) {
    int cont_2 = 0, cont_5 = 0;
    while(x && x % 2 == 0) { x /= 2; cont_2++;}
    while(x && x % 5 == 0) { x /= 5; cont_5++;}
    return my_pair(x == 0 ? INF: cont_2, x == 0 ? INF :cont_5);
}

int solve(bool first) {
    
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(j != 0) { 
                dp[i][j] = mat[i][j] + mat[i][j].min(dp[i][j-1], dp[i-1][j], first);
                if(dp[i][j] == mat[i][j] + dp[i][j-1])
                    par[i][j][first] = 'R';
                else par[i][j][first] = 'D';
            }
            else { 
                dp[i][j] = dp[i-1][j] + mat[i][j];
                par[i][j][first] = 'D';
            }
            //printf("dp[%d][%d][%d] = %d\n", i, j, first, first ? dp[i][j].F : dp[i][j].S);
        }

    if(first) return dp[n-1][n-1].F;
    else return dp[n-1][n-1].S;
}

void printPath(bool first) {

    int i = n-1, j = n-1;
    string res = "";
    
    while(i != 0 || j != 0) {
        res += par[i][j][first];
        if(par[i][j][first] == 'D') i -= 1;
        else j -= 1;
    }

    for(int i = res.size() - 1; i >= 0; i--)
        printf("%c", res[i]);
}

int main() {
 
    while(scanf("%d",&n) != EOF) {
        bool flag = false;
        int i0 = -1, j0 = -1;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) { 
                int x;
                scanf("%d", &x);
                if(x == 0) { flag = true; i0 = i; j0 = j; }
                mat[i][j] = fact2and5(x);
                //printf("mat[%d][%d] = %d, %d\n", i, j, mat[i][j].F, mat[i][j].S);
            }

        dp[0][0] = mat[0][0];
        for(int i = 1; i < n; i++) {
            dp[0][i] = mat[0][i] + dp[0][i-1];
            par[0][i][0] = par[0][i][1] = 'R';
        }
        
        int answer1 = solve(true);
        int answer2 = solve(false);
        int answer = min(answer1, answer2);
        
        if(flag && answer > 0) {
            printf("1\n");
            for(int i = 0; i < i0; i++) printf("D");
            for(int i = 0; i < j0; i++) printf("R");
            for(int i = i0; i < n-1; i++) printf("D");
            for(int i = j0; i < n-1; i++) printf("R");
            break;
        }

       printf("%d\n", answer);
        if(answer == answer2) printPath(false);
        else printPath(true);
    }

	return 0; 
}
