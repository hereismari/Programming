#include <bits/stdc++.h>
#define ll unsigned long long 
#define MAX 10000022
#define pb push_back

using namespace std;

int isTheSame(ll x, ll y) {

    int a_x[20], a_y[20];
    memset(a_x,0,sizeof a_x);
    memset(a_y,0,sizeof a_y);
    int len_x = 0, len_y = 0;

    while(x > 0) {
        a_x[x % 10]++;
        x /= 10;
        len_x++;
    }

    while(y > 0) {
        a_y[y % 10]++;
        y /= 10;
        len_y++;
    }

    if(len_x > len_y) return 1;
    if(len_x < len_y) return -1;
    for(int i = 0; i < 10; i++)
        if(a_x[i] != a_y[i]) return -1;
    return 0;
}

int main() {


    ll n;
    cin >> n;

    ll ans = 0;
    for(ll i = sqrt(n); i < sqrt(11*n); i++) {
        if(isTheSame(i*i-n, n) == 0) ans++;
    }

    cout << ans << '\n';
    return 0;
}
