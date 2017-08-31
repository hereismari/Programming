#include <bits/stdc++.h>

using namespace std;

int getSum(int b, int e, int a[]) {
    
    int res = 0;
    for(int i = b; i <= e; i++)
        for(int j = i+1; j <= e; j++)
            res += a[j] - a[i];

    return res;
}

int main() {
    
    int n;
    while(scanf("%d", &n) != EOF) {
        
        int a[n];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);

        int ans = (int)1e9;
        for(int i = 0; i < n-1; i++) {
            int aux = getSum(0, i, a) + getSum(i+1, n-1, a);
            if(aux < ans) {
                ans = aux;
            }
        }

        printf("%d\n", ans);

    }


    return 0;
}
