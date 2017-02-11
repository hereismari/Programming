#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    while(n--) {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        if(a > b) printf(">\n");
        else if(a < b) printf("<\n");
        else printf("=\n");
    }

    return 0;
}
