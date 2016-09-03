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

int gcd_extended(int a, int b, int *x, int *y) {
    
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd = gcd_extended(b % a, a, &x1, &y1);
    
    *x = y1 - (b/a)*x1;
    *y = x1;
    return gcd;
}

int n;

int main() {

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int a, b, x, y, c;
        scanf("%d %d %d", &a, &b, &c);
        int ans = gcd_extended(a, b, &x, &y);
        printf("Case %d: %s\n", i, c % ans == 0 ? "Yes" : "No");
    }

    return 0; 
}
