#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define MAX 5001000
 
using namespace std;
 
bool visited[10*MAX];
 
bool validate(int x) {
 return x < MAX && x > -MAX && !visited[x + MAX];
}

int bfs(int x, int y) {
 
   queue<pair<int,int> > q;
   memset(visited, false, sizeof visited);
   visited[x + MAX] = true;
   q.push(mp(x,0));
   while(!q.empty()) {
     int top = q.front().F;
    // printf("%d\n",top); 
     int dist = q.front().S; q.pop();
     visited[top + MAX] = true;
     if(top == y) return dist;   
     if(validate(top*2)) q.push(mp(top*2,dist + 1));
     if(validate(top*3)) q.push(mp(top*3,dist + 1));
     if(validate(top/2)) q.push(mp(floor(top/2),dist + 1));
     if(validate(top/3)) q.push(mp(floor(top/3),dist + 1));
     if(validate(top + 7)) q.push(mp(top+7,dist + 1));
     if(validate(top-7)) q.push(mp(top-7,dist + 1));
   }    
    return -1;
}
 
int main() {
     
    int n, m;
    scanf("%d %d",&n, &m);
    printf("%d", bfs(n,m));
    return 0;
}
