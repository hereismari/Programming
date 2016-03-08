#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

ll n, m, x, y;

int main() {
 
    string s;
    cin >> s;
    int l = s.size();
    scanf("%lld %lld", &n, &m);

    ll mod_n[l], mod_m[l];
    ll aux_n = 0, aux_m = 0;

    for(int i = 0; i < l; i++) {
        
        aux_n = (aux_n * 10 + (s[i] - '0')) % n;
        aux_m = (aux_m * 10 + (s[i] - '0')) % m;
        
        mod_n[i] = aux_n;
        mod_m[i] = aux_m;
    }

    int cont_10 = 1;
    for(int i = l-1; i >= 0; i--) {
        mod_m[i] = (mod_m[i] * cont_10) % m;
        cont_10 = (cont_10 * 10) % m;
    }

    for(int i = 0; i < l; i++) {
        if(mod_n[i] == 0 && i < l-1 && s[i+1] != '0' && mod_m[i] == mod_m[l-1]) {
            printf("YES\n");
            for(int j = 0; j < i+1; j++) printf("%c", s[j]);
            printf("\n");
            for(int j = i+1; j < l; j++) printf("%c", s[j]);
            printf("\n");

            return 0;
        }
    }

    printf("NO\n");
	return 0; 
}
