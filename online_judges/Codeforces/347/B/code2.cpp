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

ll binSearch(int b, int e, ll v, ll cont) {
    while(b <= e) {
        int m = (b+e)/2;
        if (v == cont*m) return m;
        else if(m*cont < v) b++;
        else e--;
    }
    return 0;
}

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
    
    ll a = 0, b = 0;
    for(int i = 1; i <= n; i++) {
        ll res = binSearch(1, n, i*neg + n, pos);
        if(res > 0 && res <= n) {
            a = res; b = i; break;
        }
    }
    
    if(a == 0 && b == 0) printf("Impossible\n");
    else {

        string ans = "";
        printf("Possible\n");
        for(int i = 0; i < s.size(); i++) {
            if(i == 0) { if(s[i] == "?") ans += SSTR(a) + ' ';}
            else if(s[i] == "?") {
                if(s[i-1] == "+") ans += SSTR(a) + ' ';
                if(s[i-1] == "-") ans += SSTR(b) + ' ';
            }
            else ans += (s[i] + ' ');
        }
        cout << ans << endl;
    }

	return 0; 
}
