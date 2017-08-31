#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m,x;
    while(scanf("%d %d",&n,&m) != EOF) {
        int ans = 0;
        for(int i = 0; i < n; i++){
            bool flag = true;
            for(int j = 0; j < m; j++){
                scanf("%d",&x);
                if(x == 0) flag = false;
            }
            if(flag) ans++;
        }

        printf("%d\n",ans);
    }

    return 0;
}
