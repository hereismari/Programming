#include <bits/stdc++.h>

using namespace std;

#define MAX 100006
#define vi vector<int>
#define pb push_back
#define vpii vector<pair<int, int > >
#define mp make_pair

int n;
vi graph[MAX];
vpii ans;
bool matched[MAX], flag;

bool dfs(int id, int par = -1) {

    matched[id] = false;
    for(int i = 0; i < graph[id].size(); i++) {
        int v = graph[id][i];
        if(v == par) continue;
        bool res = dfs(v, id);
        if(!res) {
            if(matched[id]) flag = true;
            ans.pb(mp(min(id, v), max(id, v)));
            matched[id] = true;
        }
    }

    return matched[id];
}

int main() {

    int x, y;
    while(scanf("%d", &n) != EOF) {
     
        memset(matched, false, sizeof matched);
        flag = false;
        ans.clear();
        for(int i = 1; i <= n; i++) {
            graph[i].clear();
        }

        for(int i = 0; i < n-1; i++) {
            scanf("%d %d", &x, &y);
            graph[x].pb(y);
            graph[y].pb(x);
        }
    
        dfs(1);

        if(flag) printf("N\n");
        else {    
            printf("Y\n");
            sort(ans.begin(), ans.end());
            for(vpii::iterator it = ans.begin(); it != ans.end(); it++) {
                    printf("%d %d\n", it->first, it->second);            
            }
        }
    }

    return 0;
}


