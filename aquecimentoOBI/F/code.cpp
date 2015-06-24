#include <bits/stdc++.h>
#define MAX 5010
#define IN 1
#define OUT 2
#define ESPECIAL 3
#define INF 100000

using namespace std;
vector<int> adj[MAX];
map<string,int> mapa;

int bfs(int x, int lookin){

	int i = 0;
	queue<int> q;
	int dist[MAX];
	bool visitado[MAX];

	for(int i = 0 ; i < MAX; i++) {dist[i] = INF; visitado[i] = false;}

	dist[x] = 0;
	q.push(x);
	visitado[x] = true;

	while(!q.empty()){
		int top = q.front(); q.pop();
		if(top == lookin) return dist[lookin];
		for(int i = 0; i < adj[top].size(); i++){
			if(!visitado[adj[top][i]]){
				dist[adj[top][i]] = dist[top] + 1;
				q.push(adj[top][i]);
				visitado[adj[top][i]] = true;
			}
		}
	}
}

int main(){

	int n,m;
	string s1,s2;

	scanf("%d %d",&n,&m);
	int cont = 4;
	for(int i = 0 ; i < m; i++){

		cin >> s1 >> s2;
		int a1, a2;

		if(s1 == "Entrada") a1 = IN;
		else if(s1 == "Saida")  a1 = OUT;
		else if(s1 == "*" ) a1 = ESPECIAL;
		else{
			if(mapa.find(s1) != mapa.end())
				a1 = mapa[s1];
			else {
				mapa[s1] = cont++;
				a1 = mapa[s1];
			}
		}
	
		if(s2 == "Saida") a2 = OUT;
		else if(s2 == "Entrada") a2 = IN;
		else if(s2 == "*") a2 = ESPECIAL;
		else{
			if(mapa.find(s2) != mapa.end())
				a2 = mapa[s2];
			else {
				mapa[s2] = cont++;
				a2 = mapa[s2];
			}

		}
		adj[a1].push_back(a2);
		adj[a2].push_back(a1);

	}

	int answer = 0;

	answer += bfs(IN,ESPECIAL);
	answer += bfs(ESPECIAL,OUT);

	printf("%d\n",answer);
	return 0;
}
