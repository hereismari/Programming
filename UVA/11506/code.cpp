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

	int a,c,e;
	s = 0;
	while (scanf("%d %d", &n, &e) != EOF && (n || e)) {
		t = 2*n - 3;
		memset(res, 0, sizeof res);
		AdjList.assign(2*n-2,vi());

		for(int i = 0; i < n - 2; i++){
				int id, c, u ,v;
				scanf("%d %d",&id,&c); id--;
				u = 2*id - 1;
				v= u + 1;
				res[u][v] = c;
				AdjList[u].push_back(v);	
				AdjList[v].push_back(u);	
	}

		for (int i = 0; i < e; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--;
			v--;
			res[n+u][v] += w;
			res[n+v][u] += w;
			AdjList[n+u].push_back(v);
			AdjList[n+v].push_back(u);
		}

		EdmondKarps();

		printf("%d\n",max_flow);
	}

	return 0;
}
