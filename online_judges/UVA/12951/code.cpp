#include <bits/stdc++.h>
#define INF 120000

using namespace std;

int main() {

    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        
        int aux = INF, x, max_value = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            
            scanf("%d",&x);
           
            if(x < aux || x < max_value-m){
                ans += max_value-m-aux > 0 ? max_value-m-aux : 0;
                max_value = 0;
                aux = INF;
            }
            
            aux = min(aux, x);
            max_value = max(x, max_value);
        }

        ans += max_value-m-aux > 0 ? max_value-m-aux : 0;
        printf("%d\n", ans);
    
    }
    
    return 0;
}
