#include <bits/stdc++.h>
#define MAX 110
#define INF 10000000
#define F 6

using namespace std;

int T[F];
int weight[MAX][MAX];
int dist[MAX];
int floor[MAX];

void reset(){
	for(int i = 0; i < MAX; i++)
		for(int j = 0 ; j < MAX; j++)
			{ dist[i] = INF; weight[i][j] = INF;}

}

int bfs(int n) {

  queue<int> Q;
  int inQueue[101] = {0};
  dist[0] = 0;
  inQueue[0] = true;
  Q.push(0);
  while (!Q.empty()) {
       int now = Q.front();
       inQueue[now] = false;
       Q.pop();
 
       for (int nxt = 0; nxt < MAX; nxt++) {
           if (dist[now] + weight[now][nxt] + 60 < dist[nxt]) {
                  dist[nxt] = dist[now] + weight[now][nxt] + 60;
                    if (!inQueue[nxt]) {
                        Q.push(nxt);
                        inQueue[nxt] = true;
                    }
                }
            }
        }

	return dist[n];
}

int main(){
	
	int n,k;
	while(scanf("%d %d",&k,&n) != EOF){
		reset();
		for(int i = 1 ; i <= k ; i++)
			scanf("%d",&T[i]);
		cin.ignore();
		for(int i = 1; i <= k; i++){
			string input;
			getline(cin,input);
			stringstream ss(input);
			int cont = 0;
		    while (ss >> floor[cont]) ++cont;
            for (int x = 0; x < cont; x++)
                for (int y = x + 1; y < cont; y++) {
                    int f1 = floor[x], f2 = floor[y];
                    if ((f2-f1)*T[i] < weight[f1][f2])
                        weight[f1][f2] = weight[f2][f1] = (f2-f1)*T[i];
                }
        }

		int answer = bfs(n);
		if (n == 0) printf("0\n"); 
        else if (dist[n] == INF) printf("IMPOSSIBLE\n");
        else printf("%d\n",dist[n] - 60);
	}


	return 0;
}
