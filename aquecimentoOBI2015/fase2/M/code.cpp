#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define MAX 1000
using namespace std;

char m[MAX][MAX];

bool bfs() {

    queue<pair<int,int> > q;
    q.push(mp(1,1));
    bool visited[MAX][MAX];
    memset(visited,false, sizeof visited);
    while(!q.empty()) {
        int i = q.front().F;
	int j = q.front().S;
	q.pop();
	if(!visited[i+1][j] && m[i+1][j] == '0') { visited[i+1][j] = true; q.push(mp(i+1,j)); }
        if(!visited[i-1][j] && m[i-1][j] == '0') { visited[i-1][j-1] = true; q.push(mp(i-1,j)); }
        if(!visited[i][j+1] && m[i][j+1] == '0') { visited[i][j+1] = true; q.push(mp(i,j+1)); }
        if(!visited[i][j-1] && m[i][j-1] == '0') { visited[i][j-1] = true; q.push(mp(i,j-1)); }
    }

    return visited[5][5];
}

int main() {
  	
    int n;
    scanf("%d",&n);
    while(n--){
    memset(m, '1', sizeof m);
    for(int i = 1; i <= 5; i++)
	for(int j = 1; j <= 5; j++){
		scanf("\n%c",&m[i][j]);
	}
    printf("%s", bfs() ? "COPS\n": "ROBBERS\n");
    }
    return 0;
}
