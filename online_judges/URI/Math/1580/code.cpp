#include <bits/stdc++.h>

#define ll long long int
#define MOD 1000000007
#define BASE 257
#define MAX 1005

using namespace std;

ll power(ll num, ll pow) {
    if (pow < 1) return 1;
    ll result = power(num, pow/2);
    result = (result * result) % MOD;
    if (pow % 2)
        result = (result * num) % MOD;
	return result;
}

int main() {

    ll fat[MAX];
    fat[0] = fat[1] = 1;
    for(int i = 2; i < MAX; i++) fat[i] = (fat[i-1] * i) % MOD;

    string s;
    while(cin >> s) {

        int count[30];

        ll ans = fat[s.size()];

        memset(count , 0, sizeof count);
        for(int i = 0; i < s.size(); i++) count[s[i]-'A']++;    
        
        for(int i = 0; i < 30; i++) {
            if(count[i] >= 2) {
                ans = (ans * power(fat[count[i]], MOD-2)) % MOD;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
