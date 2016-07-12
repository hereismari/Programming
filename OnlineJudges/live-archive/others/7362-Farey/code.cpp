#include <bits/stdc++.h>

using namespace std;

#define N 10100
#define ll long long int
#define pb push_back

ll s[N];

void pre() {

    bool primes[N], a[N];
    vector<int> v[N];

    memset(primes, true, sizeof primes);
    memset(s, 0, sizeof s);

    primes[0] = primes[1] = false;
    for(int i = 2; i < N; i++) {
        if(primes[i]) {
            for(int j = i+i; j < N; j += i) {
                primes[j] = false;
                v[j].pb(i);
            }
        }
    }
    
    for(int i = 2; i < N; i++) {
        
        int aux = 0;
        memset(a, false, sizeof a);
        for(int j = 0; j < v[i].size(); j++) {
            int k = v[i][j];
            while(k < i) {
                if(!a[k]) aux++;
                a[k] = true;
                k += v[i][j];
            }
        }
        s[i] = i - 1 - aux;
    }
    
    for(int i = 3; i < N; i++) s[i] += s[i-1];
}

int main() {
    
    pre();

    int n, k, x;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &k, &x);
        printf("%d %lld\n", k, s[x] + 2);
    }

    return 0;
}
