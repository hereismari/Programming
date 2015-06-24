#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxVertices 1000
#define maxEdges 1000000

int graph[maxVertices][maxVertices];
/* Input graph must be undirected,weighted and connected*/
typedef struct Edge
{
        int from,to,weight;
}Edge;
int compare(const void * x,const void * y)
{
        return (*(Edge *)x).weight - (*(Edge *)y).weight;
}
Edge E[maxEdges];
int parent[maxVertices];
void init(int vertices)
{
        int iter=0;
        for(iter=0;iter<vertices;iter++)
        {
                parent[iter]=-1;
        }

}
int Find(int vertex)
{
        if(parent[vertex]==-1)return vertex;
        return parent[vertex] = Find(parent[vertex]); /* Finding its parent as well as updating the parent 
                                                         of all vertices along this path */
}
int Union(int parent1,int parent2)
{
        /* This can be implemented in many other ways. This is one of them */
        parent[parent1] = parent2;
}
void Kruskal(int vertices,int edges)
{
        memset(graph,-1,sizeof(graph)); /* -1 represents the absence of edge between them */
        /* Sort the edges according to the weight */
        qsort(E,edges,sizeof(Edge),compare);
        /* Initialize parents of all vertices to be -1.*/
        init(vertices);
        int totalEdges = 0,edgePos=0,from,to,weight;
        Edge now;
        while(totalEdges < vertices -1)
        {
                if(edgePos==edges)
                {
                        /* Input Graph is not connected*/
                        exit(0);
                }
                now = E[edgePos++];
                from = now.from;
                to = now.to;
                weight=now.weight;
                /* See If vetices from,to are connected. If they are connected do not add this edge. */
                int parent1 = Find(from);
                int parent2 = Find(to);
                if(parent1!=parent2)
                {
                        graph[from][to] = weight;
                        Union(parent1,parent2);
                        totalEdges++;
                }
        }

}
int main()
{
        int vertices,edges;
        scanf("%d%d",&vertices,&edges);
        int iter,jter;
        int from,to,weight;
        for(iter=0;iter<edges;iter++)
        {
                scanf("%d%d%d",&from,&to,&weight);
                E[iter].from = from; 
                E[iter].to = to; 
                E[iter].weight = weight;
        }
        /* Finding MST */
        Kruskal(vertices,edges);
        /* Printing the MST */
        for(iter=0;iter<vertices;iter++)
        {
                for(jter=0;jter<vertices;jter++)
                {
                        if(graph[iter][jter]!=-1)
                        {
                                printf("Vertex %d and %d, weight %d\n",iter,jter,graph[iter][jter]);
                        }
                }
        }
        return 0;
}

