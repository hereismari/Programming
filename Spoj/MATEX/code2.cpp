#include <bits/stdc++.h>
#define SIZE 20
#define ll long long int
#define M 1000000007

using namespace std;

ll d;

struct Matrix{
    ll mat[SIZE][SIZE];
    Matrix() { memset(mat, 0,sizeof(mat));};
    Matrix operator * (const Matrix & in) const {
        Matrix aux;
        for(int i = 0; i < d;i++){
            for(int j = 0;j < d;j++){
                for(int k = 0; k < d;k++){
                    aux.mat[i][j] = (mat[i][k] * in.mat[k][j] + aux.mat[i][j]) % M;
                }
            }
        }
        return aux;
    }
};

Matrix matExpo(Matrix x, ll y){
	
	Matrix result;
	if(y == 1) return x;

	result = matExpo(x, y/2);
	result = result * result;
	if(y % 2 == 1) result = result * x;
	return result; 
}
int main() {

	Matrix a;
	ll x, y, z;
	scanf("%lld",&d);
	for(int i = 0; i < d; i++)
		for(int j = 0; j < d; j++){
			scanf("%lld",&a.mat[i][j]);
		}

	while(scanf("%lld %lld %lld",&x,&y,&z) != EOF){
		Matrix answer = matExpo(a,z);
		printf("%lld\n",answer.mat[x-1][y-1]);
	}

	return 0;
}
