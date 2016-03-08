#include <bits/stdc++.h>
#define pq priority_queue<tel>
#define MAX 1010

using namespace std;

struct tel{
	int tempo, id;
	tel(int t = 0, int i = 0){
		tempo = t;
		id = i;
	}
	
	bool operator < (const tel & t) const {
		if(t.tempo != tempo) return tempo > t.tempo;
		else return id > t.id;	
	}

};

int answer[MAX];

int main() {

	int n, m, x;
	scanf("%d %d",&n,&m);
	tel t[n];
	memset(answer, 0 , sizeof answer);
	pq q;
	for(int i = 0; i < n; i++)
		q.push(tel(0,i));

	for(int i = 0; i < m; i++){
		scanf("%d",&x);
		tel top = q.top(); q.pop();
		answer[top.id]++;
		q.push(tel(top.tempo + x, top.id));		
	}
	
	for(int i = 0; i < n; i++){
		printf("%d %d\n",i+1,answer[i]);
	}

	return 0;
}
