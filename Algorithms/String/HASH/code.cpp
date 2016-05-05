#include <bits/stdc++.h>

#define MOD 1000000007
#define BASE 257
#define MAX 1000400
#define ll long long int
#define pb push_back

using namespace std;

ll aux[MAX], hash1[MAX], hash2[MAX];
int n, m;
string s1, s2;
ll inverse;

ll power(ll num, ll pow) {
    if (pow < 1) return 1;
    ll result = power(num, pow/2);
    result = (result * result) % MOD;
    if (pow % 2)
        result = (result * num) % MOD;
	return result;
}

void preHash() {
    aux[0] = 1;
    for(int i = 1; i < MAX; i++) aux[i] = aux[i-1] * BASE % MOD;
}

// remove the i-element of hash1
void remove(int i) {
	ll aux_hash = ((((hash1[s1.size()] - hash1[i] + MOD) % MOD) * inverse) % MOD + hash1[i-1]) % MOD;
}

int main() {

    preHash();
    
    inverse = power(BASE, MOD-2);
    
    // calculating the hash
    cin >> s1;
    hash1[0] = 0;
    for(int i = 1 ; i <= s1.size(); i++) hash1[i] = (hash1[i-1] + (s1[i-1] - 'a') * aux[i-1]) % MOD;

     return 0;
}
