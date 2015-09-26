#include <bits/stdc++.h>
#define MAX 1500
#define pb push_back

using namespace std;

int a[MAX];
int n;

bool isPrime(int n) {
    for(int i = 2; i < n; i++) if(n % i == 0) return false;
    return true;
}

int main() {

    scanf("%d", &n);
   
    vector<int> ans;
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            ans.pb(i);
            for(int j = i * i; j <= n; j *= i) ans.pb(j);
        }
    }

    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) printf ("%d ", ans[i]);
    
    return 0;
}
