#include <bits/stdc++.h> 

#define MAX 1010 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;
vi adj[MAX];

int main() {
 
	scanf("%d",&n);
	
    // the vertices of the bridge will have an odd degree 
    if(n % 2 == 0) {printf("NO\n"); return 0;}
		
	printf("YES\n");

    // special case
	if(n == 1){
		printf("2 1\n1 2\n"); return 0;
	}

    // number of vertices = (number of vertices
    // in the strong connected component of degree n) + 1 = (n+2) 
    int vertices = (n+2);
    // number of edges = number of edges in connected component
    // of degree n (n*(n+1)/2) + edges of new vertice (n-1)
    // + bridge
    int edges = (((n+1)*n/2) + (n-1)/2)*2 + 1;

	printf("%d %d\n", vertices * 2, edges);
	
    // aux says if we connect or not de vertices
    int aux = 0;
    
    // creating bridge
	adj[1].pb(2);

    // connect the "roots" with all vertices of component
    // except the last one
	for(int i = 2; i < n + 1; i++){
		adj[1].pb(2*i - 1);
		adj[2].pb(2*i);
	}

    //connect rest of vertices with each other
    //respecting the components division
	for(int i = 2; i <= vertices; i++){
		for(int j = i+1; j <= vertices; j++){
				if(i != j) {
                    
                    // its okay to connect with everybody in the loop
					if(i >= n+1){
						adj[2*i - 1].pb(2*j - 1);
						adj[2*i].pb(2*j);
					}

                    // if its not the really next edge connect them
					else if(aux % 2 == 0 && j != i+1){
						adj[2*i - 1].pb(2*j - 1);
						adj[2*i].pb(2*j);
					}

                    // the same condition above basically
					else if(aux % 2 == 1 && j != i-1){
						adj[2*i - 1].pb(2*j - 1);
						adj[2*i].pb(2*j);
					}
				}
			}
			aux++;
		} 

	for(int i = 1; i <= vertices * 2; i++)
		for(int j = 0; j < adj[i].size(); j++)
			printf("%d %d\n",i,adj[i][j]);
	return 0; 
}
