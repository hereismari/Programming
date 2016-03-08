#include <bits/stdc++.h>

using namespace std;

int n, t;
string s1, s2, ans;

int main() {

    ans = "";
    
    cin >> n >> t;
    cin >> s1;
    cin >> s2;
    
    bool aux[n];
    memset(aux, false, sizeof aux);
    for(int i = 0; i < n; ++i) 
        for(char c = 'a'; c <= 'z'; ++c) {
            if (s1[i] == c || s2[i] == c) continue;
            ans += c;
            break;
        }

    int d1 = n - t, d2 = n - t;
    for (int i = 0; i < n; ++i) {
        if (!d1) break;
        if (s1[i] == s2[i]) { 
        	ans[i] = s1[i]; d1--; d2--; aux[i] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if(aux[i]) continue;
        if(d1) { ans[i] = s1[i]; d1--; aux[i] = true; continue;}
        if(d2) { ans[i] = s2[i]; d2--; aux[i] = true; continue;}
    }

    if (!d1 && !d2)
        cout << ans << endl;
    else
        cout << "-1" << endl;

    return 0;
}
