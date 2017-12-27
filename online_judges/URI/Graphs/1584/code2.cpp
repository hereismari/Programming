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
                    if(i != j)
                      //if(i != k && k != j)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * o.m[k][j]) % MOD;
                    else
                      res.m[i][j] = 0;
        
        
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
            for(int p = i; p < n; p++) {
              for(int q = j; q < n; q++) {
                int d_x = i - p, d_y = j - q;
                int aux_x = p + d_x, aux_y = j + d_y;
                if((d_x != 0 || d_y != 0) && valid[p][q]) { 
                  A.m[i * n + j][p * n + q] = 1;
                  A.m[p * n + q][i * n + j] = 1;
                  while(aux_x >= 0 && aux_x < n && aux_y >= 0 && aux_y < n) { valid[aux_x][aux_y] = false; aux_x += d_x; aux_y += d_y; }
                }
                else {
                  A.m[i * n + j][p * n + q] = 0;
                  A.m[p * n + q][i * n + j] = 0;
                }
              }
            }
          }
        }
        
        Matrix res = expMatrix(A, k, n * n);

        ll sol = 0;
        for(int i = 0; i < n*n; i++) 
          for(int j = 0; j < n*n; j++) {      
              printf("%d, %d: %lld\n", i, j, res.m[i][j]);             
              if(i != j) sol = (sol + res.m[i][j]) % MOD;        
            }
        printf("%lld\n", sol);
    }

    return 0;
}
