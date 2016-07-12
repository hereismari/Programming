#include <bits/stdc++.h>

using namespace std;

int getSum(int x) { return (x*(x + 1))/2; }
int getOdd(int x) { return x * x; }
int getEven(int x) { return x * (x+1); }

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int k, x;
        scanf("%d %d", &k, &x);
        printf("%d %d %d %d\n", k, getSum(x), getOdd(x), getEven(x)); 
    }


    return 0;
}
