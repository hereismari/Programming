#include <bits/stdc++.h> 

using namespace std; 

#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

#define MAX 1000010 

int primes[MAX];

void calcPrimes() {

    for(int i = 0; i < MAX; i++) primes[i] = 0;
    primes[0] = primes[1] = 0;

    for(int i = 2; i < MAX; i++) {
        if(!primes[i]) 
            for(int j = i; j < MAX; j += i) primes[j]++;
    }
}


int main() {
 
    calcPrimes();
    int x;
    while(scanf("%d", &x) != EOF && x != 0) {
        printf("%d : %d\n", x, primes[x]);
    }

	return 0; 
}
