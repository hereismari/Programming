#include <bits/stdc++.h>
#define ll long long int
#define MAX 120
#define MOD 10000
using namespace std;

ll n, m;
int a, b;

struct Matrix{

    int m[MAX][MAX];
    Matrix operator * (const Matrix & o) const {
        Matrix aux;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    aux.m[i][j] = (aux.m[i][j] + m[i][k]*o.m[k][j]) % MOD;
        return aux;
    }
};

Matrix adj;
Matrix matExpo(Matrix x, ll y){
    Matrix result;
    if(y <= 1) return x;
    result = matExpo(x, y/2);
    result = result * result;
    if(y % 2 == 1) result = result * x;
    return result;
}

int main() {

    while(scanf("%lld %lld",&n, &m) != EOF) {
        scanf("%d %d",&a,&b);
        int x;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj.m[i][j] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 4; j++){
                scanf("%d",&x);
                adj.m[i][x-1]++;
            }
        }

//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < n; j++)
//                printf("%d ",adj.m[i][j]);
 
        Matrix ans = matExpo(adj,m);
        printf("%d\n",ans.m[b-1][a-1]); }
    return 0;
}
