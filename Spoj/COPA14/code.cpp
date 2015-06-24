#include <bits/stdc++.h>
#define R 1
#define F 0
#define MAX 100000

using namespace std;

int pset[MAX];

void init(int n) { for(int i = 0; i <= n; i++) pset[i] = i;}
int findSet(int x) { return (x == pset[x]) ? x : findSet(pset[x]); }
bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
void connect(int x, int y) { pset[findSet(x)] = findSet(y); }

struct edge{

	int tipo;
	int a,b,w;
	edge(int tipo,int a,int b, int w){
		this->tipo = tipo;
		this->a = a;
		this->b = b;
		this->w = w;
	}	

};

bool comp(edge e1, edge e2){

	if(e1.tipo != e2.tipo)
		return e1.tipo < e2.tipo;
	else
		return e1.w < e2.w;
}

vector<edge> edges;

int kruskal(){
	sort(edges.begin(),edges.end(),comp);
	int answer = 0;

	for(int i = 0; i < edges.size(); i++)
		if(!isSameSet(edges[i].a,edges[i].b))
		{
			connect(edges[i].a,edges[i].b);
			answer += edges[i].w;
		}

	return answer;
}

int main(){

	int n,f,r;
	scanf("%d %d %d",&n,&f,&r);
	
	init(n);
	int x,y,weight;

	for(int i = 0; i < f; i++){
		scanf("%d %d %d",&x,&y,&weight);
		edges.push_back(edge(F,x,y,weight));
	}

	for(int i = 0; i < r; i++){
		scanf("%d %d %d",&x,&y,&weight);
		edges.push_back(edge(R,x,y,weight));
	}


	printf("%d\n",kruskal());
	return 0;
}
