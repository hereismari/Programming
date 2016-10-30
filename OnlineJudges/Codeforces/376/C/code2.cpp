#include <bits/stdc++.h>

using namespace std;

#define MAX 200100

int u[MAX], rank[MAX], a[MAX];

int findpar(int x) {
    return (x == u[x]) ? x : (u[x] = findpar(u[x]));
}

bool sameSet(int x, int y) {
    return findpar(x) == findpar(y);
}

void connect(int x, int y) {
    if(!sameSet(x, y)) {
        int par_x = findpar(x), par_y = findpar(y);
        if(rank[par_x] > rank[par_y]) {
            u[par_y] = par_x;
            rank[par_x]++;
        }
        else {
            rank[par_y]++;
            u[par_x] = par_y;
        }
    }
}

int main() {

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    memset(rank, 0, sizeof rank);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
        u[i] = i;
    }

    int x, y;
    int ans = 0;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        x--; y--;
 
       connect(x, y);
    }

    set<int> s[n];
    for(int i = 0; i < n; i++) {
        s[findpar(u[i])].insert(i);
    }

    int colors[k], id1[k];
    memset(colors, 0, sizeof colors);
    memset(id1, 0, sizeof id1);

    for(int i = 0; i < n; i++) {
        int cont = -1;
        for(set<int>::iterator it = s[i].begin(); it != s[i].end(); it++) {
            if(id1[a[*it]] != i) {
                colors[a[*it]] = 1;
                id1[a[*it]] = i;
            }
            else
                colors[a[*it]]++;

            if(cont == -1)
                cont = a[*it];
            else if(colors[a[*it]] > colors[cont])
                cont = a[*it];
        }
        if(cont >= 0)
            ans += s[i].size() - colors[cont];
    }

    printf("%d\n", ans);

    return 0;
}
