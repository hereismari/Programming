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

	while (scanf("%d", &n), n) {

		memset(res, 0, sizeof res);

		scanf("%d %d %d", &s, &t, &c);
		s--;
		t--;

		for (int i = 0; i < c; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--;
			v--;
			res[u][v] += w;
			res[v][u] += w;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		EdmondKarps();

		printf("Network %d\nThe bandwidth is %d.\n\n", cnt++, max_flow);
	}

	return 0;
}
