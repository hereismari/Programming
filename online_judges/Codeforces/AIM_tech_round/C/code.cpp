#include <bits/stdc++.h> 

#define MAX 523
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y;
bool graph[MAX][MAX], possible;
char value[MAX];

void dfs(int node, char v) {

    value[node] = v;
    for(int i = 1; i <= n; i++) {
        if(graph[node][i] && value[i] == 'f')
            dfs(i, v == 'a' ? 'c' : 'a');
        else if(graph[node][i] && value[i] == v) possible = false;
    }
}

int main() {
 
    while(scanf("%d %d",&n, &m) != EOF){

        memset(graph, true, sizeof graph);
        memset(value, 'f', sizeof value);
        possible = true;
        for(int i = 1; i <= n; i++) graph[i][i] = false;

        for(int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            graph[x][y] = graph[y][x] = false;
        }

        for(int i = 1; i <= n; i++) {
            bool flag = false;
            for(int j = 1; j <= n; j++)
                flag |= graph[i][j];
            
            if(!flag) value[i] = 'b';

        }

        for(int i = 1; i <= n; i++)
            if(value[i] == 'f')
                dfs(i, 'a');
    
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                //printf("value[%d] = %c graph[%d][%d] = %d\n", i, value[i], i, j, graph[i][j]);
                if(!graph[i][j] && value[i] == 'a' && value[j] == 'c')
                    possible = false;
                else if(!graph[i][j] && value[i] == 'c' && value[i] == 'a')
                    possible = false;
            }
        
        if(possible) {
            printf("Yes\n");
            for(int i = 1; i <= n; i++) printf("%c", value[i]);
        }
        else
            printf("No");
        puts("");
    
    }

	return 0; 
}
