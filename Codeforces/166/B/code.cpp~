#include <bits/stdc++.h> 
#define N 100005
#define MAX 600
#define ll long long int
#define pb push_back
#define vi vector<int> 
 
using namespace std; 

int n,m,x,y;
int m1[MAX][MAX];
vi prime;
bool p[N];

void primes() {

	memset(p,true, sizeof p);
	p[0] = p[1] = false;
	for(int i = 2; i < N; i++){
		if(p[i]){
			for(ll j = i; j < N; j += i)
				p[j] = false;
			prime.pb(i);		
		}
	}
}

int bin_search(int x){
	
	int i = 0; int j = prime.size()-1; int m = j/2;
	while(i < j){
		if(prime[m] < x) i = m + 1;
		else if(prime[m] > x) j = m - 1;
		else return prime[m];
		m = (i+j)/2;
	
	}
	while(prime[j] < x) j++;
	return prime[j];
}

int main() {
 
	primes();
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m ; j++){
			scanf("%d",&x);
		//	printf("%d %d\n",x,bin_search(x));
			m1[i][j] = bin_search(x) - x;
		}
	}

	ll answer = INT_MAX;
	for(int i = 0; i < n ; i++){
		ll aux = 0;
		for(int j = 0; j < m; j++)
			aux += m1[i][j];
		answer = min(aux,answer);
	}

	for(int i = 0; i < m; i++){
		ll aux = 0;
		for(int j = 0; j < n; j++)
			aux += m1[j][i];
		answer = min(aux,answer);
	}
	
	printf("%lld\n",answer);
	return 0; 
}
