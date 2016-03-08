#include <bits/stdc++.h> 

#define MAX 1000100 
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
 
using namespace std; 

ll n, m, x, y;

int main() {
 
    scanf("%lld %lld", &n, &m);

    ll ans = max(n * 2, m * 3);

    ll biggerN = n * 2;
    ll biggerM = m * 3;

    for(int i = 3, j = 2; i <= n && j <= m; i += 3, j += 2) {
        ll aux_1 = (biggerN + 2 + (((biggerN + 2) % 6 == 0 && biggerN  + 2 <= ans? 2 : 0))); 
        ll aux_2 = (biggerM + 3 + (((biggerM + 3)% 6 == 0 && biggerM + 3 <= ans? 3 : 0))); 
        if(aux_1 <= aux_2) {
            biggerN = aux_1;
            ans = max(ans, biggerN);
        }
        else {
            biggerM = aux_2;
            ans = max(ans, biggerM);
        }
    }

    printf("%lld\n", ans);
	return 0; 
}
