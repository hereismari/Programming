#include <bits/stdc++.h>
#define BASE 32
#define MAX 100
#define ll unsigned long long
using namespace std;

void base32(ll n) {

    int x = 0;
    char aux[MAX];
    char c;
    while(n >= 1) {
        c = n % BASE < 10 ?(n % BASE + '0') : ((n % BASE) -10 + 'A');
        n /= BASE;
        aux[x++] = c;
    }

    for(int i = x-1; i >=0 ; i--) printf("%c", aux[i]);
    cout << '\n';
}

int main() {
    ll n;
    while(true){
        cin >> n;
        if(n == 0) {printf("0"); break;}
        base32(n);
    }

    return 0;
}
