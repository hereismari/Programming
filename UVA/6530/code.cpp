#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    return a.S - a.F < b.S - b.F;
}

int main() {

    int n, g;
    while(scanf("%d %d",&n,&g) != EOF){
        pair<int,int> a[n];
        for(int i = 0; i < n; i++){
            scanf("%d %d",&a[i].F,&a[i].S);
        }

        sort(a,a+n,comp);
        int ans = 0;
        for(int i = 0; i < n; i++){
//            printf("%d %d\n",a[i].F,a[i].S);
            if(a[i].F > a[i].S) ans += 3;
            else if(a[i].S - a[i].F + 1 <= g){ g -= a[i].S - a[i].F + 1; ans += 3;}
            else if(a[i].S - a[i].F <= g){ g -= a[i].S - a[i].F; ans += 1;}
            else if(a[i].S - a[i].F == 0) ans += 1;
        }

        printf("%d\n",ans);
    }

    return 0;
}
