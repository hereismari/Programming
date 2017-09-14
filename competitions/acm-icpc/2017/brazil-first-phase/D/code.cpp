#include <bits/stdc++.h>

# define MAX 1000010
# define MAX_F 1000

using namespace std;

vector<long long int> primos;
bool p[MAX];
long long int fact[MAX_F];

void sieve() {

	for(int i = 0; i < MAX; i++) p[i] = true;
	
	p[0] = p[1] = false;
	for(int i = 2; i < MAX; i++) {
		if(p[i]) {
			for(int j = i+i; j < MAX; j += i) {
				p[j] = false;
			}
			primos.push_back(i);
		}
	}
}

void calc_fact() {
	fact[0] = 1;
	for(int i = 1; i < MAX_F; i++) fact[i] = i * fact[i-1];
}

long long int comb(int n, int m) {
	if(n >= m)
		return fact[n]/(fact[m] * fact[n-m]);
	else
		return 0;
}

int main() {

	sieve();
	calc_fact();

	long long int n;
	scanf("%lld", &n);
	
	int i = 0;
	long long int ans = 0;
	long long int cont = 0;
	
	while(n != 1 && i < primos.size()) {
		if(n % primos[i] == 0) {
			cont++;	
		}
		while(n % primos[i] == 0) n /= primos[i];
	
		i++;
	}
	
	if(n != 1 && cont > 0) cont++;
	
	for(int i = 2; i <= cont; i++) {
		ans += comb(cont, i);
	}
	printf("%lld\n", ans);
	
	return 0;
}
