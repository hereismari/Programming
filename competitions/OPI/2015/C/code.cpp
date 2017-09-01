#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    ll n, case_test, a, b;
    scanf("%lld",&n);
    for(int i = 0; i < n; i++){
            scanf("%lld %lld/%lld",&case_test, &a , &b);
            if(a == b) printf("%lld 1/2\n",case_test);
            else if(b == 1) printf("%lld 1/%lld\n",case_test, a+1);
            else{
                int subida = a/b;
                a = a - b*(subida);
                int aux = a;
                a = b;
                b = b-aux;
                b = b + a*subida;
                printf("%lld %lld/%lld\n",case_test, a, b);
            }
    }
    return 0;
}
