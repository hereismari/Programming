#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int inverse(int d) {
   int aux = 0;
   while(d != 0) {
      aux *= 10;
      aux += d % 10;
      d/=10;
   }
   return aux;
}

int bfs(int n, int m){

   int dist[MAX];
   map<int,int> visited;
   memset(dist,INT_MAX,sizeof dist);
   dist[n] = 0;
   queue <int> q;
   q.push(n);

   while(!q.empty()) {
	int top = q.front(); q.pop();
	int inv = inverse(top);
	if (top + 1 == m || inv == m) return dist[top] + 1;
	if (!visited[top+1]) {q.push(top+1); dist[top+1] = dist[top] + 1; visited[top+1] = 1;}
	if (!visited[inv]) {q.push(inv); dist[inv] = dist[top] +1; visited[inv] = 1;}
   }
}

int main() {

    int t,n,m;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        scanf("%d %d",&n,&m);
        printf("%d\n",bfs(n,m));
    }

    return 0;
}
