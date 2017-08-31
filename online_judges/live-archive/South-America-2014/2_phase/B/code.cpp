#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll unsigned long long
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

ll n, a, b;

int main() {
 
    while(scanf("%lld %lld",&a, &b) != EOF){
        
        string s;
        cin >> s;
        n = s.size();

        ll ans = 0;
        for(int i = 0, j = n-1; i < j;) {
            if(s[i] == 'B') i++;
            else if(s[i] == 'W' && s[j] == 'B') {
                ans += min(a, (a-b) * (j-i));
                i++; j--;
            }
            else j--;
        }

        cout << ans << endl;
    }

	return 0; 
}
