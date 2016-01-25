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

int main() {
 
    string s1, s2;

    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

    int ones[m+1], zeros[m+1];
    for(int i = 1; i <= m; i++) ones[i] = ones[i-1] + (s2[i-1] == '1');
    for(int i = 1; i <= m; i++) zeros[i] = zeros[i-1] + (s2[i-1] == '0');
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(s1[i] == '0') ans += (ones[m - n + i + 1] - ones[i]);
        else ans += (zeros[m - n + i + 1] - zeros[i]);
   }

    printf("%lld\n", ans);

	return 0; 
}
