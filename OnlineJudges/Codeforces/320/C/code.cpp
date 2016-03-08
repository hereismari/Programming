#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
    ll a,b;
    cin >> a >>b;
    if(a < b) printf("-1\n");
    else printf("%.12f\n",(a+b)/(2.*((a+b)/(2*b))));
    return 0;
}
