#include <bits/stdc++.h>
#define MAX_NODES 110  // the maximum number of nodes in the graph
#define INF 2147483646  // represents infity
#define UNINITIALIZED -1 // value for node with no parent
 
using namespace std; 
 
//represents the capacities of the edges
int capacities[MAX_NODES][MAX_NODES];
// shows how much flow has passed through an edge 
int flowPassed[MAX_NODES][MAX_NODES];
// represents the graph. The graph must contain the negative edges too!
vector<int> graph[MAX_NODES];
// shows the parents of the nodes of the path built by the BFS   
int parentsList[MAX_NODES];       
// shows the maximum flow to a node in the path built by the BFS
int currentPathCapacity[MAX_NODES];  
 
int bfs(int startNode, int endNode) {

 memset(parentsList, UNINITIALIZED, sizeof(parentsList));
 memset(currentPathCapacity, 0, sizeof(currentPathCapacity));
 
 queue<int> q;
 q.push(startNode);
 
 parentsList[startNode]=-2;
 currentPathCapacity[startNode]=INF;
 
 while(!q.empty()) {
  int currentNode = q.front(); q.pop();
 
  for(int i=0; i<graph[currentNode].size(); i++) {

   int to = graph[currentNode][i];

   if(parentsList[to] == UNINITIALIZED) {

    if(capacities[currentNode][to] - flowPassed[currentNode][to] > 0) {

     // we update the parent of the future node to be the current node
     parentsList[to] = currentNode;

    // we check which is the minimum residual edge capacity so far
     currentPathCapacity[to] = min(currentPathCapacity[currentNode], 
     capacities[currentNode][to] - flowPassed[currentNode][to]);
     
     // if we have reached the end node the bfs should terminate
     if(to == endNode) return currentPathCapacity[endNode];
 
     // we add our future node to the queue
     q.push(to);
    }
   }
  }
 }
 
 return 0;
}
 
int edmondsKarp(int startNode, int endNode) {

 int maxFlow=0;
  
 while(true) {

  // we find an augmented path and the maximum flow corresponding to it
  int flow=bfs(startNode, endNode);
   
  // if we can't find anymore paths the flow will be 0
  if(flow == 0)  break;
 
  maxFlow +=flow;
  int currentNode=endNode;
  
  // we update the passed flow matrix
  while(currentNode != startNode) {

   int previousNode = parentsList[currentNode];
   flowPassed[previousNode][currentNode] += flow;
   flowPassed[currentNode][previousNode] -= flow;
 
   currentNode=previousNode;
  }
 }
 
 return maxFlow;
}
 
int main() {

  int n;
  int count = 1;
  while(1){

  scanf("%d",&n);
  if(n == 0) break;

  for(int i = 0; i <= n; i++) graph[i].clear();
  for(int i = 0; i <= n; i++)
	for(int j = 0 ; j <= n; j++){
		 capacities[i][j] = 0;			
		 flowPassed[i][j] = 0;
	}
 int edgesCount;
 
 int source, sink;
   scanf("%d %d %d",&source,&sink,&edgesCount);
 
 for(int edge=0; edge<edgesCount; edge++) {

  int from, to, capacity;
  scanf("%d %d %d",&from,&to,&capacity);

  capacities[from][to] += capacity;
  capacities[to][from] += capacity;
  graph[from].push_back(to);
 
  //adding the negative edge
  graph[to].push_back(from);
 }
 
 int maxFlow = edmondsKarp(source, sink);
 printf("Network %d\n",count++);
 printf("The bandwidth is %d.\n\n",maxFlow);

 }
 return 0;
}
