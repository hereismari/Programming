#include <bits/stdc++.h>
#define MAX 110

using namespace std;

int x, ans[MAX];
int main() {

    int n,m;
    scanf("%d %d",&n,&m);
    memset(ans,0,sizeof ans);

    for(int i = 0; i < m; i++){
        int index = 1;
        int result = 0;
        for(int j = 1; j <= n; j++){
            scanf("%d",&x);
            if(x > result) { result = x; index = j;}
        }
        ans[index]++;
    }

    int index = 1;
    int result = 0;
    for(int i = 1; i <= n; i++){
        if(ans[i] > result) { result = ans[i]; index = i;}
    }

    printf("%d\n",index);
    return 0;
}

