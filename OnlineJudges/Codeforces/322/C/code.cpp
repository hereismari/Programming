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

bool comp(int k, int j) {
    return (10 - k % 10) < (10 - j % 10);
}

int main() {
 
    int ans = 0;
    scanf("%d %d", &n, &m);
        int a[n];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n, comp);
        int cont = 0;
        for(int i = 0; i < n; i++) {
            int v = 10 - (a[i] % 10);
            if(m >= v && a[i] + v <= 100) {
                m -= v;
                a[i] += v;
            }
            ans += a[i]/10;
            cont += 100 - a[i];
        }  

        printf("%d\n", ans + min(m / 10, cont / 10));

	return 0; 
}
