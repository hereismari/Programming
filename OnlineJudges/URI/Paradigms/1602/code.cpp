#include <bits/stdc++.h>

using namespace std;

#define MAX 2000010
#define ll long long int

bool primes[MAX];
vector<ll> p;

void sieve() {

    memset(primes, true, sizeof primes);
    primes[0] = primes[1] = false;
    for(int i = 2; i < MAX; i++)
        if(primes[i]) {
            for(int j = i+i; j < MAX; j += i)
                primes[j] = false;
            p.push_back(i);
        }
}

int get_number_div(ll n) {
    
    int ans = 1, pf = 0;
    while(p[pf] * p[pf] <= n) {
        int aux = 0;
        while(n % p[pf] == 0) { n /= p[pf]; aux++; }
        ans *= (aux + 1);
        pf++;
    }
    if(n != 1) ans *= 2;
    return ans;
}

int main() {

    sieve();

    int ans[MAX];
    ans[2] = 1;
    for(int i = 3; i < MAX; i++) {
        bool flag = false;
        if (primes[i]) flag = true;
        else if(sqrt(i) == (int)sqrt(i) && primes[get_number_div(i)])
            flag = true;
        ans[i] = ans[i-1] + flag;
    }

    int x;
    while(scanf("%d", &x) != EOF) {
        printf("%d\n", ans[x]);
    }
}
