#include <bits/stdc++.h>
#define INF 1e9
#define MAX_V 105

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int res[MAX_V][MAX_V], max_flow, f, s, t;
vi AdjList[MAX_V];
vi parent;

int n, c, cnt = 1;

void argment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (parent[v] != -1) {
		argment(parent[v], min(minEdge, res[parent[v]][v]));
		res[parent[v]][v] -= f;
		res[v][parent[v]] += f;
	}
}

void EdmondKarps() {

	max_flow = 0;

	while (1) {
		f = 0;
		bitset<MAX_V> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		parent.assign(MAX_V, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					parent[v] = u;
				}
			}
		}

		argment(t, INF);
		if (f == 0)
			break;
		max_flow += f;
	}
}

int main() {

	int N1, N2,x;
	int m;
	N1 = 1;
	while (scanf("%d", &n), n) {
		N2 = n + 1;
		memset(res, 0, sizeof res);

		for(int i = 0; i < n; i++){
			scanf("%d",&x);
			res[N1+i][N2+i] = x;
			AdjList[N1+i].push_back(N2+i);
			AdjList[N2+i].push_back(N1+i);
		}

		scanf("%d %d %d", &s, &t, &c);
		s--;
		t--;

		for (int i = 0; i < c; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--;
			v--;
			res[N2 + u][N1 + v] += w;
			AdjList[N2 + u].push_back(N1 + v);
			AdjList[N1 + v].push_back(N2 + u);
		}
		
		int B,D;
		scanf("%d %d",&B,&D);

		for(int i=0;i<B;i++){
            scanf("%d",&x);
            x--;
            res[0][N1+x]=INT_MAX;
            AdjList[0].push_back(N1+x);
            AdjList[N1+x].push_back(0);
        }
        
        for(int i=0;i<D;i++){
            scanf("%d",&x);
            x--;
            res[N2+x][2*n+1]=INT_MAX;
            AdjList[N2+x].push_back(2*n+1);
            AdjList[2*n+1].push_back(N2+x);
        }
        
		EdmondKarps();

		printf("%d\n",max_flow);
	}

	return 0;
}
