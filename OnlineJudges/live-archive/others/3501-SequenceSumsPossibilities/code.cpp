#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int solve(int n) {

    int res = 0;

    for(int b = 1; (b * (b+1))/2 < n; b++) {
        int a = n - (b * (b+1))/2;
        if(a % (b+1) == 0) res++;
    }

    return res;

}

int main() {

    int t;
    scanf("%d", &t);
    while(t--) {

        int id, n;
        scanf("%d %d", &id, &n);
        printf("%d %d\n", id, solve(n));
    }


    return 0;
}
