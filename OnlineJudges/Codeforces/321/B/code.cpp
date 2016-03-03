#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

struct company {

    ll dist, value;
    company(ll d=0, ll v=0){
        value = v, dist = d;
    }

    bool operator < (const company &c) const {
        return dist < c.dist;
    }
};

ll n, d, m, x, y, ans;
vector<ll> v;
company a[MAX];

void compress() {

    ll aux = 0;
    for(int i = 0, j = 0; i < n; i++){
        aux += a[i].value;
        while(a[i].dist - a[j].dist >= d) aux -= a[j++].value;        
        ans = max(ans, aux);
    }
}

int main() {
 
    scanf("%lld %lld", &n, &d);
    
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld",&x, &y);
        a[i] = company(x, y);
    }

    sort(a, a+n);
    compress();
    printf("%lld\n", ans);

	return 0; 
}
