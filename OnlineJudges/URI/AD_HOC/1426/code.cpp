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
#define INF 1000000000

int n, m, x, y;

int main() {
 
    while(scanf("%d", &n) != EOF) {
        
        for(int i = 0; i < n; i++) {
            
            int mat[10][10];
        
            for(int j = 1; j <= 9; j++)
                for(int k = 1; k <= 9; k++) mat[j][k] = 0;

            for(int j = 1; j <= 9; j += 2)
                for(int k = 1; k <= j; k+=2)
                    scanf("%d", &mat[j][k]);

            for(int k = 1; k <= 9; k += 2) {
                int a = (mat[7][k] - mat[9][k] - mat[9][k+2])/2;
                mat[9][k+1] = a;
                mat[8][k] = mat[9][k] + a;
                mat[8][k+1] = mat[9][k+2] + a;
            }
    
            for(int j = 7; j >= 1; j--)
                for(int k = 1; k <= 9; k++)
                    mat[j][k] = mat[j+1][k] + mat[j+1][k+1];

            for(int j = 1; j <= 9; j++) {
                for(int k = 1; k <= j; k++) {
                    printf("%d", mat[j][k]);
                    if(k != j) printf(" ");
                }
                printf("\n");
            }
        
        }
    
    }

	return 0; 
}
