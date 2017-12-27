#include <bits/stdc++.h>
#define SIZE 50
#define ll long long int

const ll MOD = 1000000007;

using namespace std;

struct Matrix {
    ll m[SIZE][SIZE];
    int n;
    Matrix() {}
    Matrix(int n) { this->n = n; memset(m, 0, sizeof m); }
    Matrix operator * (const Matrix & o) const {
        Matrix res(this->n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * o.m[k][j]) % MOD;
                    
        
        return res;
    }
};

Matrix expMatrix(Matrix A, ll exp, int n){
    if(exp <= 1) return A;
    Matrix res(n);
    res = expMatrix(A, exp/2, n);
    res = res * res;
    if(exp & 1) res = res * A;
    return res;
}

int main() {

    ll k;
    int n;
    while(scanf("%d %lld", &n, &k) != EOF){
        
        if(k == 0LL) { printf("%d\n", n * n); continue; }
        
        Matrix A(n * n);
        bool valid[n][n];
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
          
            memset(valid, true, sizeof valid);
          
            for(int p = 0; p < n; p++) {
              for(int q = 0; q < n; q++) {
                int d_x = p - i, d_y = q - j;
                int aux_x = p + d_x, aux_y = q + d_y;
                if(d_x != 0 || d_y != 0)
                  while(aux_x >= 0 && aux_x < n && aux_y >= 0 && aux_y < n) { valid[aux_x][aux_y] = false; aux_x += d_x; aux_y += d_y; }
              }
            }
            
             for(int p = 0; p < n; p++)
              for(int q = 0; q < n; q++)
                if(valid[p][q] && (p != i || q != j)) {
                  A.m[i * n + j][p * n + q] = 1;
                }
          }
        }
        
        Matrix res = expMatrix(A, k, n * n);

        ll sol = 0;
        for(int i = 0; i < n*n; i++) 
          for(int j = 0; j < n*n; j++) {      
              //printf("%d, %d: %lld\n", i, j, res.m[i][j]);             
              sol = (sol + res.m[i][j]) % MOD;        
            }
        printf("%lld\n", sol);
    }

    return 0;
}
