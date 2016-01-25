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

int n, m, x, y;

int main() {
 
    scanf("%d", &n);
    
    ll a[n]; ll min = 1000000001;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] < min) min = a[i];
    }
    
    ll ans = min * n;

    ll pre[n], pos[n], aux = -1;
    memset(pre, -1, sizeof pre);
    memset(pos, -1, sizeof pos);
    ll first, last;
    
    for(int i = 0; i < n; i++) {
        if(a[i] == min) { if(aux == -1) first = i; pre[i] = aux; aux = i; }
    }

    aux = -1;
    for(int i = n-1; i >= 0; i--) {
        if(a[i] == min) { if(aux == -1) last = i; pos[i] = aux; aux = i; }
    }

    int ans2 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == min) {
            int aux2 = 0;
            if(pre[i] == -1 && pos[i] == -1) aux2 = n;
            else if(pre[i] == -1) aux2 = max(i + n - last, pos[i] - i);
            else if(pos[i] == -1) aux2 = max(i - pre[i], first + n - i);
            else aux2 = max(i - pre[i], pos[i] - i);
            if (aux2 > ans2) ans2 = aux2;
        }
    }

    printf("%lld\n", ans + ans2 - 1);

	return 0; 
}
