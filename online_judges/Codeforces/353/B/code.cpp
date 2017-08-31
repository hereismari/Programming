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
#define INF 1000000000

int n, m, x, y;

int main() {

    int a, b, c, d;
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

    int a1[4];
    a1[0] = a + b; a1[1] = a + c;
    a1[2] = c + d; a1[3] = b + d;
    
    sort(a1, a1 + 4);
    
    int dif = a1[3] - a1[0] + 1;
    ll ans = max(n - dif + 1, 0) * (n * 1LL);
    printf("%lld\n", ans);
    
    return 0; 
}
