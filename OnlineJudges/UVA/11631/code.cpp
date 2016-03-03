#include <bits/stdc++.h>
#define MAX 700000
using namespace std;

struct node{

	int a,b,w;
	node(int a,int b, int w)
	{ this-> a = a; this->b = b; this->w = w;}
};

vector<node> edges;
bool comp(node a, node b) { return a.w < b.w; }
int uni[MAX];
int initSet() { for(int i = 0 ; i < MAX; i++) uni[i] = i;}
int findSet(int x){return (x == uni[x]) ? x : (uni[x] = findSet(uni[x]));} 
void connect(int x, int y) {uni[findSet(x)] = findSet(y); }
bool isSameSet(int x, int y){ return findSet(x) == findSet(y);}

int kruskal(){
	initSet();
	sort(edges.begin(),edges.end(),comp);
	int answer = 0;
	for(int i = 0 ; i < edges.size(); i++)
		if(!isSameSet(edges[i].a,edges[i].b))
			{ answer += edges[i].w; connect(edges[i].a,edges[i].b);}
	return answer;
}

int main(){
	int n,m;
	int x,y,w;
	while(1){

		scanf("%d %d",&m,&n);
		if(n == 0) break;
		int cont = 0;
		edges.clear();
		for(int i = 0 ; i < n; i++){
			scanf("%d %d %d",&x,&y,&w);
			edges.push_back(node(x,y,w));
			cont += w;
	}
		
		printf("%d\n",cont - kruskal());		
	}

	return 0;
}
