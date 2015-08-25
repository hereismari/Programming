#include <bits/stdc++.h>
#define MAX 30
using namespace std;

int main() {

    int n;
    while(scanf("%d",&n) != EOF) {

        int x;
        int freq[MAX];
        memset(freq,0,sizeof freq);
        for(int i = 0; i < n; i++){
            scanf("%d",&x);
            freq[x+11]++;
        }

        int ans = INT_MAX;
        int m = 0;
        int a[MAX*3];

        for(int i = 0; i < MAX; i++) if(freq[i] % 2 == 1) a[m++] = i;
        for(int i = 0; i < m; i++) a[i+m] = a[i] + 24;
        if(m == 0) ans = 0;

        for(int i = 0; i < m; i++){
            int aux = 0;
            for(int j = 0; j < m; j+=2)
                aux += a[i+j+1] - a[i+j];
            ans = min(ans,aux);
        }

        printf("%d\n",ans);
    }

    return 0;
}
