#include <bits/stdc++.h> 

#define MAX 100000010 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
#define SIZE 3

using namespace std; 

ll n,m,x,y;
ll dp[MAX];
ll base;

struct Matrix{

    ll  m[SIZE][SIZE];
	Matrix() { memset(m,0,sizeof m); }
	Matrix operator * (const Matrix & other) const {
	
		Matrix aux;
		for(int i = 0; i < SIZE; i++)
			for(int j = 0; j < SIZE; j++)
				for(int k = 0; k < SIZE; k++)
					aux.m[i][j] = (aux.m[i][j] +  m[i][k]*(other.m[k][j])) % base;
		return aux;
	};

};

Matrix powerM(Matrix m, ll power){

	Matrix result;
	if(power <= 1) return m;
	
	result = powerM(m,power/2);
	result = result * result;
	if(power % 2 == 1) result = result * m;
	return result;	
}

int main() {

	int count = 1;
	Matrix z;
	z.m[0][0] = z.m[0][1] = z.m[0][2] = 1;
	z.m[1][0] = 1; z.m[1][1] = z.m[1][2] = 0;
	z.m[2][0] = z.m[2][1] = 0; z.m[2][2] = 1;
	while(true) {

		scanf("%lld %lld",&n, &base);
		if(n == 0 && base == 0) break;

		Matrix aux = powerM(z,n-1);
		ll result = (aux.m[0][0] + aux.m[0][1]) % base;
		result = (result + aux.m[0][2]) % base;
		if(n == 0 || n == 1) result = 1;
		printf("Case %d: %lld %lld %lld\n",count++, n, base, result % base);
	}

	return 0; 
}
