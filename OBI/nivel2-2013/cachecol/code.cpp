#include <bits/stdc++.h>
#define SIZE 4
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
	if(y <= 1) return x;

	result = matExpo(x, y/2);
	result = result * result;
	if(y % 2 == 1) result = result * x;
	return result; 
}
int main() {

	Matrix a;
	a.mat[0][0] = 3;
	a.mat[0][1] = 2;
	a.mat[1][0] = 2;
	a.mat[1][1] = 2;

	d = 4;
	ll n;
	scanf("%lld",&n);
	Matrix aux = matExpo(a,n-1);
	if(n == 1) printf("%d\n",12);
		else {
		ll answer = 0;
		for(int i = 0; i < SIZE; i++)
			for(int j = 0; j < SIZE; j++){
				answer += aux.mat[i][j];
				answer = answer % M;
			}
		answer = (answer * 6) % M;
		printf("%lld\n", answer);
	}
	return 0;
}
