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

#define MAX 10000007
#define INF 1000000000

int n, m, x, y;
int primes[MAX];

void sieve() {

    for(int i = 0; i < MAX; i++) primes[i] = 0;

    for(int i = 2; i < MAX; i++) {
        if(primes[i] == 0) {
            for(int j = i + i; j < MAX; j += i)
                if(primes[j] == 0) primes[j] = i;
        }
    }
}

void printFact(int number) {
    
    printf("1");
    if(number == 1) {
        printf("\n"); return;
    }
    if (primes[number] != 0) 
        while(primes[number] != 0 && number % primes[number] == 0) { 
            printf(" x %d", primes[number]);
            number /= primes[number];
        }

    printf(" x %d", number);
    printf("\n");
}

int main() {
 
    sieve();
    while(scanf("%d", &n) != EOF) {
        printFact(n);
    }

	return 0; 
}
