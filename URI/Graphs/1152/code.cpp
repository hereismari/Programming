#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

struct edge {
	int a, b, w;
	edge(int a=0, int b=0, int w=0){
		this->a = a;
		this->b = b;
		this->w = w;
	}

	bool operator < (const edge & e) const {
		return w < e.w;
	}

};

int n,m,x,y,w;
edge e[MAX];
ll answer;
int unionF[MAX];
int rank[MAX];

void initSet() { for(int i = 0; i < MAX; i++){ unionF[i] = i; rank[i] = 0;}}
int findSet(int a) { return (a == unionF[a]) ? a : (unionF[a] = findSet(unionF[a])); }
bool connected(int a,int b) { return findSet(a) == findSet(b); }
void connect(int a, int b){
	if(rank[a] > rank[b]) unionF[b] = a;
	else if(rank[b] > rank[a]) unionF[a] = b;
	else { rank[a]++; unionF[b] = a;}
}
void kruskall(){

	initSet();
	for(int i = 0; i < m; i++){
		int par_a = findSet(e[i].a);
		int par_b = findSet(e[i].b);
		if(!connected(par_a,par_b))
		{
			connect(par_a,par_b);
			answer -= e[i].w;
		}
	}
}

int main() {
 
	while(true) {

		scanf("%d %d",&n,&m);
		if(n == 0 && m == 0) break;
		answer = 0;
		for(int i = 0; i < m; i++){
			scanf("%d %d %d",&x,&y,&w);
			e[i] = edge(x,y,w);		
			answer += w;	
		}

		sort(e,e+m);
		kruskall();
		printf("%lld\n",answer);
	}
	return 0; 
}
