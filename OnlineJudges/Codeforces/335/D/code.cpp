#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y;

struct edge {

    int w, used, id;
    edge(int w = 0, int used = false, int id = 0) {
        this -> w = w;
        this -> used = used;
        this -> id = id;
    }

    bool operator < (const edge &o) const {
        if(w != o.w) return w < o.w;
        return used > o.used;
    }
};

int main() {
 
    while(scanf("%d %d",&n, &m) != EOF){
        
        edge e[m];
        pii ans[m];

        for(int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            e[i] = edge(x, y, i);
        }

        sort(e, e + m);

        int tree_counter = 2;
        int from = 3;
        int to = 2;

        for(int i = 0; i < m; i++) {
            if(e[i].used) {
                ans[e[i].id] = mp(1, tree_counter++);
            } else {
                if(to >= from) { from++; to = 2;}
                
                if(from >= tree_counter) { puts("-1"); return 0; }
                ans[e[i].id] = mp(from, to++);
            }
        }

        for(int i = 0; i < m; i++)
            printf("%d %d\n", ans[i].F, ans[i].S);

    }

    return 0; 
}
