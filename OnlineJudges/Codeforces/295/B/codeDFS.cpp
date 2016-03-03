#include <bits/stdc++.h>
#define MAX 500000
#define F first
#define S second

using namespace std;
int n, m;
bool visited[MAX];

int answer(int x) {
	queue<pair<int,int> > q;
	int cont = 0;
	q.push(make_pair(x,0));
	while(!q.empty()){
		pair<int,int> top = q.front(); q.pop();
		visited[top.F] = true;
		if(top.F == m) return top.S;
		if(!visited[top.F-1] && top.F >= 0)
			q.push(make_pair(top.F-1, top.S + 1));
		if(!visited[top.F*2] && top.F * 2 < m * 2)
			q.push(make_pair(top.F*2, top.S + 1));
	}
}

int main(){

	scanf("%d %d",&n,&m);
	printf("%d\n",answer(n));
	return 0;
}
