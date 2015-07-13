#include <bits/stdc++.h>
#define SIZE 20
#define ll long long int
#define MOD 1000000007

using namespace std;
ll x,y,z;
ll n;

void one(ll x[SIZE][SIZE]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = (i == j);
}

void matmult(long long  a[SIZE][SIZE],long long  b[SIZE][SIZE],long long c[SIZE][SIZE]) //multiply matrix a and b. put result in c
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
                c[i][j]=c[i][j]%MOD;
            }
        }
    }
 
}
void matpow(long long a[SIZE][SIZE],int k,long long ans[SIZE][SIZE]) //find ( Z^n )% M and return result in ans
{
 
    long long temp[SIZE][SIZE];
    one(ans); //assign ans= the identity matrix
    while(k > 0) {
        if(k & 1) {
            matmult(ans,a,temp);
            for(int i = 0;i < n;i++)
                for(int j=0;j<n;j++)
                    ans[i][j]=temp[i][j];
        }
		matmult(a,a,temp);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ans[i][j]=temp[i][j];
		 k=k/2;
	}
}
/*
long long findFibonacci(long long k) {
     
    long long fib;
    if(k>2)
    {
        long long int Z[2][2]={{1,1},{1,0}},result[2][2];//modify matrix a[][] for other recurrence relations
        matpow(Z,n-2,result);
        fib=result[0][0]*1 + result[0][1]*0;    //final multiplication of Z^(n-2) with the initial terms of the series
    }
    else
        fib=k-1;
         
    return fib;
}
*/
int main() {
	ll a[SIZE][SIZE],tmp[SIZE][SIZE];
	ll ans[SIZE][SIZE];
	scanf("%lld",&n);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++){
			scanf("%lld",&a[i][j]);
		}

	while(scanf("%lld %lld %lld",&x,&y,&z) != EOF) {
		matpow(a,z,ans);
		printf("%lld\n",ans[x-1][y-1]);
	}

	return 0;
}
