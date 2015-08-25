#include <bits/stdc++.h>

#define MOD 1000000007
#define BASE 257
#define MAX 600400
#define ll long long int

using namespace std;

ll aux[MAX];
int n, m;
set<ll> st;

void preHash() {
	aux[0] = 1;
    for(int i = 1; i < MAX; i++) aux[i] = aux[i-1] * BASE % MOD;
}

ll buildHash(string s){
    ll ans = 0;
    int l = s.length();
    for(int i = 0; i < l; i++) ans = (ans * BASE + s[i]) % MOD;
    return ans;
}

bool verify(string s){
    int l = s.length();
    ll s_hash = buildHash(s);
    for(int i = 0; i < l; i++){
        for(int c = 'a'; c <= 'c'; c++){
            if(s[i] == c) continue;
            if(st.find((((c-s[i]) * aux[l-i-1] + s_hash) % MOD + MOD) % MOD) !=st.end())
                 return true;
        }
    }
    return false;
}

int main() {

	preHash();
	string s;
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n ; i++){
        cin >> s;
        st.insert(buildHash(s));
    }
    for(int i = 0; i < m; i++){
        cin >> s;
		printf("%s\n",verify(s)?"YES":"NO");
    }

    return 0;
}
