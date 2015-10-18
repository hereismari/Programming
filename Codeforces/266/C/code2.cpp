#include <bits/stdc++.h> 

#define MAX 1000010 
#define EPS 1e-7

#define ll long long
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

int a[MAX];
ll cnt[MAX];

int main() {
    
    int n;
    scanf("%d", &n);
    
    ll s = 0;
    for(int i = 0 ; i < n ; ++i) { cin >> a[i]; s += a[i]; }
    if (s % 3 != 0) puts("0");
    else {
        s /= 3;
        ll aux = 0;
        for(int i = n-1; i >= 0; --i) { aux += a[i]; if (aux == s) cnt[i] = 1; }
        for(int i = n-2 ; i >= 0; --i) cnt[i] += cnt[i+1];
        
        long long ans = 0;
        aux = 0;
        for(int i = 0 ; i+2 < n ; ++i) {
            aux += a[i];
            if (aux == s)
                ans += cnt[i+2];
        }

        cout << ans << "\n";
    }
    return 0;
}
