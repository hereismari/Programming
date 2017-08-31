#include <bits/stdc++.h> 

using namespace std; 

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

#define MAX 1000100  

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

int main() {

    vector<string> s;
    string aux;
    
    while(cin >> aux) {
        s.pb(aux);
    }
    
    ll neg = 0, pos = 0;
    int n = atoi(s[s.size()-1].c_str());

    for(int i = 0; s[i] != "="; i++) {
        if(i == 0) { if(s[i] == "?") pos++; }
        else {
            if((s[i] == "?") && (s[i-1] == "+")) pos++;
            else if((s[i] == "?") && (s[i-1] == "-")) neg++;
        }
    }
  
    printf("%lld %lld\n", pos, neg);
    if(pos*n - neg < n || pos - neg*n > n) printf("Impossible\n");
    else {

        printf("Possible\n");
        for(int i = 0; i < s.size(); i++) {
            if(i == 0) { 
                if(s[i] == "?") { 
                    if(pos >
                    ans += SSTR(n) + ' ';  
                    neg--;
                }
            }
            else if(s[i] == "?") {
                if(s[i-1] == "+" && neg) {
                    ans += SSTR(n) + ' '; neg--;
                }
                else if(s[i-1] == "+") {
                    ans += SSTR(v/pos) + ' '; 
                    v -= (v/pos);
                    pos--;
                }
                if(s[i-1] == "-") ans += SSTR(n) + ' ';
            }
            else ans += (s[i] + ' ');
        }
        cout << ans << endl;
    }
    

	return 0; 
}
