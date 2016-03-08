#include <bits/stdc++.h> 

#define MAX 100010 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define qpi queue< pair<int,int> >
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;
int dist[MAX];
int cont[MAX];

void bfs(int k) {

	bool visit[MAX];
	memset(visit,false,sizeof visit);	
	qpi q;
	q.push(mp(k,0));

	while(!q.empty()){

		pii top = q.top(); q.pop();
		if(top > MAX) continue;
		if(top < 1) continue;
		if(visit[top.F]) continue;
		
		visit[top.F] = true;
		dist[top.F] += top.S;
		cont[top.F]++;
	
		q.push(top.F/2, top.S+1);
		q.push(top.F*2, top.S+1);
	}
}

int main() {
 
	scanf("%d",&n);
	memset(dist,0,sizeof dist);
	memset(cont,0,sizeof cont);

	for(int i = 0; i < n; i++){
		scanf("%d",&x);	
		bfs(x);
	}

	int answer = INT_MAX;
	for(int i = 1; i < MAX; i++)
		if(cont[i] == n && dist[i] < answer)
			answer = dist[i];
	
	printf("%d\n",answer);
	return 0; 
}
