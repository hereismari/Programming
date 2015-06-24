// Program to print Vertex Cover of a given undirected graph
#include <bits/stdc++.h>
#define MAX 10000

using namespace std;
 
list<int> adj[MAX];  // Pointer to an array containing adjacency lists

void addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Since the graph is undirected
}
 
// The function to print vertex cover
int vertexCover(int V)
{
    // Initialize all vertices as not visited.
    bool visited[V];
    for (int i=0; i<V; i++)
        visited[i] = false;
 
    list<int>::iterator i;
 
    // Consider all edges one by one
    for (int u=0; u<V; u++)
    {
        // An edge is only picked when both visited[u] and visited[v]
        // are false
        if (visited[u] == false)
        {
            // Go through all adjacents of u and pick the first not
            // yet visited vertex (We are basically picking an edge
            // (u, v) from remaining edges.
            for ( i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
                     // Add the vertices (u, v) to the result set.
                     // We make the vertex u and v visited so that
                     // all edges from/to them would be ignored
                     visited[v] = true;
                     visited[u]  = true;
                     break;
                }
            }
        }
    }
 

	int cont = 0;
    // Print the vertex cover
    for (int i=0; i<V; i++)
        if (visited[i])
			cont += 1;

	return cont;          

}
 
int main() {
	int t, n, u , v; 
	scanf("%d",&t);

	for(int i = 0; i < t; i++){
		scanf("%d",&n);
		for(int j = 0; j < 121; j++)
			adj[j].clear();
		for(int j = 0 ; j < n ; j++){
			scanf("%d %d",&u,&v);
			addEdge(u,v);
		}

		printf("%d\n",vertexCover(120));
	}

    return 0;
}

