#include <bits/stdc++.h>

#define MOD 1000000007
#define BASE 257
#define MAX 400040
#define ll long long int
#define pb push_back

using namespace std;

ll aux[MAX], B[MAX];
ll hash[3][MAX], aux_hash[MAX];

int n, m;
string s[3], s_aux;

ll inverse;
int cont;

ll power(ll num, ll pow) {
    if (pow < 1) return 1;
    ll res = power(num, pow/2);
    res = (res * res) % MOD;
    if (pow % 2)
       	res = (res * num) % MOD;
	return res;
}

void preHash() {
	
	aux[0] = 1;
    for(int i = 1; i < MAX; i++) aux[i] = (aux[i-1] * BASE) % MOD;
    
    ll inv_B = power(BASE, MOD-2);
    B[0] = 1;
    for(int i = 1; i < MAX; i++) B[i] = (B[i-1] * inv_B) % MOD;

}

void calcHash() {
	aux_hash[0] = 0;
	for(int j = 1; j <= s_aux.size(); j++) aux_hash[j] = (aux_hash[j-1] + (s_aux[j-1] - 'a')*aux[j-1]) % MOD;
}

int verify(int b) {
	
	int res = 0;
	cont = s_aux.size() - s[b].size() - 1;
	
	for(int i = 1; i <= s_aux.size(); i++) {
		
		ll inverse = B[s_aux.size()-i];
		ll aux_1 = (((aux_hash[s_aux.size()] - aux_hash[s_aux.size()-i] + MOD) % MOD) * inverse) % MOD;
		
		ll aux_2 = 0;
		
		if(i > s[b].size()) {
			inverse = B[cont];
			cont--;
			aux_2 = (((aux_hash[s_aux.size()] - aux_hash[s_aux.size()-i+s[b].size()] + MOD) % MOD) * inverse) % MOD;
		}
		
		ll aux_3 = (aux_1 - aux_2 + MOD) % MOD;
		if(aux_3 == hash[b][min(i, int(s[b].size()))]) res = i;
	}
	
	return res;
}

int verify3(int a, int b) {
	
	int res = 0;
	cont = s[a].size() - s[b].size() - 1;
	
	for(int i = 1; i <= s[a].size(); i++) {
		
		ll inverse = B[s[a].size()-i];
		
		ll aux_1 = (((hash[a][s[a].size()] - hash[a][s[a].size()-i] + MOD) % MOD) * inverse) % MOD;
		ll aux_2 = 0;
		
		if(i > s[b].size()) {
			inverse = B[cont];
			cont--;
			aux_2 = (((hash[a][s[a].size()] - hash[a][s[a].size()-i+s[b].size()] + MOD) % MOD) * inverse) % MOD;
		}
		
		ll aux_3 = (aux_1 - aux_2 + MOD) % MOD;
		if(aux_3 == hash[b][min(i, int(s[b].size()))]) res = i;
	}
	
	return res;
}

int verify2(int a, int b, int c) {
	
	int div = verify3(a, b);
	s_aux = "";
	
	for(int i = 1; i <= s[a].size(); i++) s_aux += s[a][i-1];
	for(int i = div+1; i <= s[b].size(); i++) s_aux += s[b][i-1];
	
	calcHash();
	return min(int(s[b].size()), div) + min(int(s[c].size()), verify(c));
}

int main() {

	preHash();
    
    inverse = power(BASE, MOD-2);
    
    for(int i = 0; i < 3; i++) {
		cin >> s[i];
    	hash[i][0] = 0;
    	for(int j = 1 ; j <= s[i].size(); j++) hash[i][j] = (hash[i][j-1] + (s[i][j-1] - 'a') * aux[j-1]) % MOD;
    }
    
	int ans = 0;
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
				if(i != j && i != k && j != k) {
					ans = max(ans, verify2(i, j, k));
				}
	
	printf("%d\n", s[0].size() + s[1].size() + s[2].size() - ans);
    return 0;
}
