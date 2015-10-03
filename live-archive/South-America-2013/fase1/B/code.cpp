#include <bits/stdc++.h>
#define MOD 1000000
#define SIZE 2
#define ll long long int

using namespace std;

struct Matrix {
    ll m[SIZE][SIZE];
    Matrix() { memset(m,0,sizeof m);}
    Matrix operator * (const Matrix & o) const {
        Matrix res;
        for(int i = 0; i < SIZE; i++)
            for(int j = 0; j < SIZE; j++)
                for(int k = 0; k < SIZE; k++)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * o.m[k][j]) % MOD;
        return res;
    }
};

Matrix expMatrix(Matrix A, ll exp){
    if(exp <= 1) return A;
    Matrix res;
    res = expMatrix(A,exp/2);
    res = res * res;
    if(exp & 1) res = res * A;
    return res;
}

int main() {

    ll k, n, m;
    while(scanf("%lld %lld %lld",&k,&n,&m) != EOF){
        Matrix A;
        A.m[0][0] = n % MOD, A.m[0][1] = m % MOD, A.m[1][0] = 1, A.m[1][1] = 0;
        Matrix res = expMatrix(A,k/5);
        printf("%06lld\n",res.m[0][0]);
    }

    return 0;
}
