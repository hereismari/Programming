#include <bits/stdc++.h>
#define MAX 10020
#define WHITE -1
#define GRAY 0
#define BLACK 1
 
using namespace std;
 
int color[MAX];
vector<int> adj[MAX];
int x,y,a,b;
int time1;
bool flag;

bool dfs(int x){
 
	time1 += 1; 
	color[x] = GRAY;
    
    for(int i = 0; i < adj[x].size(); i++){
        if(color[adj[x][i]] == GRAY) flag = true;
        else if(color[adj[x][i]] == WHITE) dfs(adj[x][i]);
    }
	color[x] = BLACK;
} 
 
int main() {
 
    int n;
    scanf("%d",&n);
 
    for(int i = 0 ; i < n ; i++){
		time1 = 0; 
        scanf("%d %d",&a, &b);
        for(int j = 0; j <= a; j++) { adj[j].clear(); color[j] = WHITE;}
        for(int j = 0 ; j < b; j++){
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);
        }
 
        flag = false;
        for(int i = 1; i <= a; i++){
            if(color[i] == WHITE)
				dfs(i);
        }
 
        if(flag) printf("SIM\n");
        else printf("NAO\n");
    }
 
    return 0;
}
