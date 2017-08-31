#include <bits/stdc++.h>
#define MAX 105

using namespace std;

struct node{
	int a;
	int weight;
	int b;	
	node(int a = 0,int b = 0 ,int weight = 1){
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
};
bool comp(node a, node b) { return a.weight < b.weight; }

vector<node> adj;
int uni[MAX];
void reset(){ adj.clear(); for(int i = 0; i < MAX; i++) uni[i] = i; }
int findSet(int x){return  (x == uni[x])? x : (uni[x] = findSet(uni[x]));}
bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }
void connect(int a, int b) { uni[findSet(a)] = findSet(b);}

void kruskal(int size){

	for(int i = 0 ; i < size; i++) 
		if(!isSameSet(adj[i].a,adj[i].b))
		{ printf("%d %d\n",min(adj[i].a,adj[i].b),max(adj[i].a,adj[i].b)); connect(adj[i].a,adj[i].b); }
}

int main(){
	int cont = 1;
	int n,m;
	int x,y,p;
	while(1){
		scanf("%d %d",&n,&m);
		if(n == 0) break;
		reset();
		for(int i = 0 ; i < m; i++){
			scanf("%d %d %d",&x,&y,&p);
			adj.push_back(node(x,y,p));
		}
		printf("Teste %d\n",cont++);
		sort(adj.begin(),adj.end(),comp);
		kruskal(m);
		printf("\n");
	}

	return 0;
}
