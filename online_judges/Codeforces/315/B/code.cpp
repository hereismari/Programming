#include <bits/stdc++.h>
#define MAX 10000011

using namespace std;

int a[MAX];
int ans[MAX];
int cont[MAX];

int main() {

    int n, x;
    scanf("%d",&n);

    memset(cont,0,sizeof cont);
    memset(ans,-1,sizeof ans);

    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]); if(a[i]<= n && a[i] >= 1) cont[a[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(cont[a[i]] >= 1){
            ans[i] = a[i]; cont[a[i]] = -1;
        }
    }

    for(int i = 0, j = 1; i < n; i++){
        if(ans[i] == -1){
            while(cont[j] == -1) j++;
            ans[i] = j;
            cont[j] = -1;
        }
    }

    printf("%d",ans[0]);
    for(int i = 1; i < n; i++)
        printf(" %d",ans[i]);

    return 0;
}
