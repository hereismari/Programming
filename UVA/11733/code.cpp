#include <bits/stdc++.h>
#define INF 1000009
#define MAX 100024

using namespace std;

struct data{

	int a,b,w;
	data(int a, int b, int w){
		this->a=a;
		this->b=b;
		this->w=w;
	}
};

bool comp(data a, data b) { return a.w < b.w; }

vector<data> edges;
int uni[MAX];
void initUni(){ for(int i = 0; i < MAX; i++) uni[i] = i; }
int findSet(int x) { return (x == uni[x]) ? x : (uni[x] = findSet(uni[x]));}
bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
void connect(int x, int y) { uni[findSet(x)] = findSet(y); }

pair<int,int> kruskal(int a, int v){
	sort(edges.begin(),edges.end(),comp);
	int answer = 0;
	int k = 0;
	for(int i = 0; i < edges.size(); i++){
		if(edges[i].w >= a || k > v -1) break;
	
		if(!isSameSet(edges[i].a,edges[i].b))
			{
				answer += edges[i].w; connect(edges[i].a,edges[i].b);
				k++;
			}
	}
	int cont = 0;
	for(int i = 1; i <= v; i++){
		if(uni[i] == i){
			answer += a;
			cont+= 1;
		}
	}

	return make_pair(answer,cont);
}

int main(){

	int t;
	int n,m,a;
	int x,y,c;

	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%d %d %d",&n,&m,&a);
		initUni();		
		edges.clear();
		
		for(int j = 0 ; j < m; j++)
		{
			scanf("%d %d %d",&x,&y,&c);
			edges.push_back(data(x,y,c));
		}

		pair<int,int> answer = kruskal(a,n);
		printf("Case #%d: %d %d\n",i+1,answer.first,answer.second);
			
	}

	return 0;
}
