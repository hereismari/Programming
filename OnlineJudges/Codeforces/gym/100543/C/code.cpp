#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll somaPA(long long a) {
    return ((1+a)*a)/2;
}

int main() {
    ll n, t, shift, resn;
    scanf("%I64d", &t);
    
    while(t--) {
    scanf("%I64d", &n);
        shift = -1;
        for(ll i = 2; somaPA(i) <= n; i++) {
            if((n-somaPA(i))%i == 0) {
                shift = (n-somaPA(i))/i;
                resn = i;
                break;
            }
        }
        
        if(shift == -1)
            cout << "IMPOSSIBLE" << endl;
        else {
            cout << n << " = ";
            for(ll i = 1; i <= resn; i++) {
                cout << i+shift;
                if(i < resn)
                    cout << " + ";
                else
                    cout << endl;
            }
        }
    }

    return 0;
}
