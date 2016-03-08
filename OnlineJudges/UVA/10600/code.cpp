#include <bits/stdc++.h>
#define MAX 1005
#define INF 1000000
using namespace std;

struct node{
	int a;
	int weight;
	int b;	
	bool used;
	node(int a = 0,int b = 0 ,int weight = 1){
		this->a = a;
		this->b = b;
		this->weight = weight;
		used = false;
	}
};

bool comp(node a, node b) { return a.weight < b.weight; }

vector<node> adj;
vector<int> possible_answers;
int uni[MAX];
void reset(){ for(int i = 0; i < MAX; i++) uni[i] = i; }
int findSet(int x){return  (x == uni[x])? x : (uni[x] = findSet(uni[x]));}
bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }
void connect(int a, int b) { uni[findSet(a)] = findSet(b);}

int  kruskal(){
	int answer = 0;
	for(int i = 0 ; i < adj.size(); i++){ 
		if(!isSameSet(adj[i].a,adj[i].b))
		{ 
			adj[i].used = true;
			answer += adj[i].weight; connect(adj[i].a,adj[i].b); }
	}
	return answer;
}

void kruskal2(int off, int n){
	int answer = 0;
	reset();
	int cont = 0;
	for(int i = 0 ; i < adj.size(); i++){ 
		if(!isSameSet(adj[i].a,adj[i].b) && i != off)
		{ 
			cont += 1;
			answer += adj[i].weight; connect(adj[i].a,adj[i].b); }
	}
	if(cont >= n-1)
	possible_answers.push_back(answer);
}

int main(){
	int cont = 1;
	int n,m;
	int x,y,p;
	int t;
	scanf("%d",&t);
	for(int k = 0; k < t; k++){
		scanf("%d %d",&n,&m);
		reset();
		adj.clear();
		possible_answers.clear();
		for(int i = 0 ; i < m; i++){
			scanf("%d %d %d",&x,&y,&p);
			adj.push_back(node(x,y,p));
		}
		sort(adj.begin(),adj.end(),comp);
		int answer1 = kruskal();
		for(int i = 0; i < m; i++)
			if(adj[i].used)
				kruskal2(i,n);
		sort(possible_answers.begin(),possible_answers.end());
		printf("%d %d\n",answer1,possible_answers[0]);
	}

	return 0;
}
