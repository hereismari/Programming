#include <stdio.h>
#include <vector>
#include <set>
#include <stdlib.h>
#include<string.h>
#define MAX_EDGES 1000
#define MAX_VERTICES 1000

using namespace std;

typedef struct _edge {int from,to,weight;} edge;

int comp(const void * a, const void * b){ 
  return (((edge*)a)->weight)-(((edge*)b)->weight);
}

int graph[MAX_VERTICES][MAX_VERTICES];
edge e[MAX_EDGES];
int parent[MAX_VERTICES];

void init(int vertices){
	
	for(int i = 0 ; i < vertices ; i++)
		parent[i] = -1;
	
}

int find(int v){
	if(parent[v] == -1) return v;
	return parent[v] = find(parent[v]);
}

int unions(int v1, int v2){
	parent[v1] = v2;
}

void kruskal(int vertices, int edges){

	memset(graph,-1,sizeof(graph));
	qsort(e, vertices , sizeof(edge), comp);
	init(vertices);
	int from,to,weight,totalEdges = 0 , edgepos = 0;
	while(totalEdges < vertices-1) {
		
		//graph is not connected
		if (edges == totalEdges) return;
		
		edge now = e[edgepos++];
		from = now.from;
		to = now.to;
		weight = now.weight;
		int p1 = find(from);
		int p2 = find(to);
		if (p1 != p2){
			graph[from][to] = weight; 
			unions(p1,p2);
			totalEdges++;
		}
	 }
}

int main(){
		
	int vertices,edges;
    scanf("%d %d",&vertices,&edges);
	int iter,jter;
    int from,to,weight;

	for(iter=0;iter<edges;iter++)
    {
            scanf("%d %d %d",&from,&to,&weight);
            e[iter].from = from; 
            e[iter].to = to; 
            e[iter].weight = weight;
     }

    /* Finding MST */
     kruskal(vertices,edges);
    /* Printing the MST */
     for(iter=0;iter<vertices;iter++)
	    for(jter=0;jter<vertices;jter++)
            if(graph[iter][jter]!=-1)
               printf("Vertex %d and %d, weight %d\n",iter,jter,graph[iter][jter]);

    return 0;
}
