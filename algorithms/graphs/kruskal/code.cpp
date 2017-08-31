#include<bits/stdc++.h>

using namespace std;

#define MAX_E 1000
#define MAX_V 1000
#define vi vector<int> 
#define ll long long int

struct edge {
    
    int from, to, weight;

    edge(int from = -1, int to = -1, int weight = -1) {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }

    bool operator < (const edge &o) const {
        return weight < o.weight;
    }
};

struct unionFind {

    vi p, rank; // remember: vi is vector<int>

    unionFind(int N) { 
        rank.assign(N, 0); p.assign(N, 0); 
        for (int i = 0; i < N; i++) p[i] = i; 
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) { 
        if (!isSameSet(i, j)) { 
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
                else p[x] = y;
                if (rank[x] == rank[y]) rank[y]++; 
        }
    } 
};

edge e[MAX_E];

ll kruskal(int vertices, int edges) {

	sort(e, e + vertices);

    unionFind u = unionFind(vertices + 1);
	
    ll ans = 0;
    for(int i = 0; i < edges; i++) {
        if(!u.isSameSet(e[i].to, e[i].from)) {
            ans += e[i].weight;
            u.unionSet(e[i].to, e[i].from);
        }
    }

    return ans;
}

int main(){
		
	int vertices, edges;
    int from, to, weight;
    
    scanf("%d %d",&vertices, &edges);

	for(int i = 0;i < edges; i++) {
        scanf("%d %d %d",&from,&to,&weight);
        e[i] = edge(from, to, weight);
     }

    /* Finding MST */
    printf("%lld\n", kruskal(vertices, edges));

    return 0;
}
