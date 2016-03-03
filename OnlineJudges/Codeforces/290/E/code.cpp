#include <bits/stdc++.h>
#define INF INT_MAX
#define MAX_V 202
#define MAX 200010

#define ll long long int

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int res[MAX_V][MAX_V], max_flow, f, s=0, t=MAX_V-1;
vi AdjList[MAX_V];
vi parent;
vi even, odd, answer[MAX_V];
bool primes_[MAX], visited[MAX_V];
int v[MAX_V+2];
int n, c, cnt = 1,aux;

void primes(){

    for (int i = 2; i * i <= MAX; i++)
        if (!primes_[i])
            for (int j = i * i; j <= MAX; j += i)
                primes_[j] = true;

}

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (parent[v] != -1) {
		augment(parent[v], min(minEdge, res[parent[v]][v]));
		res[parent[v]][v] -= f;
		res[v][parent[v]] += f;
	}
}

int EdmondKarps() {

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
			for (int i = 0; i < (int) AdjList[u].size(); i++) {				int v = AdjList[u][i];
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					parent[v] = u;
				}
			}
		}

		augment(t, INF);
		if (f == 0)
			break;
		max_flow += f;
	}
	return max_flow;
}

void addEdge(int u, int v, int cap){
	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
	res[u][v] = cap;
}

void dfs (int x, int parent){

    if (visited[x]) return;

    visited[x] = true;
    answer[aux].push_back(x);
    for (int i = 0; i < AdjList[x].size(); i++){
        int w = AdjList[x][i];
        if (w != parent)
            if(v[x] % 2 && res[x][w] == 0)
                dfs(w, x);
            else if(v[x] % 2 == 0 && res[x][w] == 1)
                    dfs(w, x);
    }

}

int main() {
    
	int n,x;
    scanf ("%d", &n);
	primes();

	for (int i = 0; i < n; i++){
        scanf ("%d", &v[i+1]);
        if (v[i+1] % 2)
            odd.push_back(i + 1);
        else
            even.push_back(i + 1);
    }

    for (int i = 0; i < odd.size(); i++)
        addEdge(s,odd[i],2);

    for (int i = 0; i < even.size(); i++)
        addEdge(even[i],t,2);

    for (int i = 0; i < odd.size(); i++)
        for (int j = 0; j < even.size(); j++)
            if (!primes_[v[odd[i]] + v[even[j]]])
				addEdge(odd[i],even[j],1);

    int flow = EdmondKarps();

    if (flow != n){
        printf("Impossible");
        return 0;
    }

    for (int i = 0; i < MAX_V; i++) visited[i] = false;

    aux = 0;

    for (int i = 0; i < odd.size(); i++){
        int v = odd[i];
        if (!visited[v]){
            dfs(v, v);
            aux++;
        }
    }

    printf ("%d\n", aux);

    for (int i = 0; i < aux; i++){
        printf("%d ",answer[i].size());
        for (int j = 0; j < answer[i].size(); j++)
            printf("%d ",answer[i][j]);
        printf ("\n");
    }    

	return 0;
}
