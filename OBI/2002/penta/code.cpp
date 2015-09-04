#include <bits/stdc++.h>
#define INF 1000001
#define NUM 25
#define MAX 200000

using namespace std;

set<int> st[NUM];
set<int> palco;
bool noPalco[NUM];
int n, m, a[MAX];

void removeMaisLonge() {
    int removido = -1, maxValue = -1;
    for(int i = 1; i < NUM; i++){
        if(noPalco[i] && *st[i].begin() > maxValue){
            maxValue = *st[i].begin();
            removido = i;
        }
    }

//    printf("removeu %d %d\n", removido, maxValue);
    noPalco[removido] = false;
    palco.erase(removido);
}

int main() {

    int teste = 1;
    while(scanf("%d %d",&n,&m) == 2 && n > 0) {
        for(int i = 1; i <= NUM; i++) {st[i].clear(); st[i].insert(INF); }
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            st[a[i]].insert(i);
        }

        palco.clear();
        memset(noPalco, false, sizeof noPalco);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(palco.size() == m && !noPalco[a[i]]) {
                removeMaisLonge();
                palco.insert(a[i]);
                st[a[i]].erase(*st[a[i]].begin());
                ans++;
                noPalco[a[i]] = true;
            }
            else if(!noPalco[a[i]]) {
                palco.insert(a[i]);
                st[a[i]].erase(*st[a[i]].begin());
                noPalco[a[i]] = true;
            }
            else 
                st[a[i]].erase(*st[a[i]].begin());
        }
        printf("Teste %d\n%d\n\n",teste++, ans);
    }
    return 0;
}
