#include <bits/stdc++.h>
#define MAX 2000100

using namespace std;

bool primes[MAX];

void sieve() {
    memset(primes, true, sizeof primes);
    primes[0] = primes[1] = false;
    for(int i = 2; i < MAX; i++){
        if(primes[i])
            for(int j = i+i; j < MAX; j += i) primes[j] = false;
    }
}

bool rub(int x) {

    int aux = x;
    int inv_x = 0;

    while(aux > 0){
        inv_x = inv_x*10 + aux % 10;
        aux /= 10;
    }

    return inv_x == x;
}

int main() {

    int p, q;
    scanf("%d %d",&p,&q);
    sieve();

    int pr = 0, r = 0;
    int ans = -1;
    for(int i = 1; i < MAX; i++){
        if(primes[i]) pr++;
        if(rub(i)) r++;
        if(q*pr <= p*r) ans = i;
    }

    printf("%d\n",ans);
    return 0;
}
