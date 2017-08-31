#include <bits/stdc++.h>
#define dist(a,b) (sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)))
#define MAX 10000
using namespace std;

struct pos{
	int x;
	int y;
	int id;
	pos(){};
	pos(int x, int y, int id){
		this->x = x;
		this->y = y;
		this->id = id;
	}
};

struct data {
	pos a;
	pos b;
	double weight;
	bool used;
	data(){};
	data(pos a, pos b){
		this->a = a;
		this->b = b;
		this->weight = dist(a,b);
		this-> used = false;
	}
};

bool comp(data a,data b) {  return a.weight < b.weight; }

int uni[MAX];
int _size;
void initUni(int n){ for(int i = 0 ; i < n; i++) uni[i] = i; _size = n; }
int findSet(int x){return  (x == uni[x]) ? x : (uni[x] = findSet(uni[x]));}
bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
void connect(int x, int y) { uni[findSet(x)] = findSet(y); _size--; }
int getSize() { return _size; }
vector<data> edges;
vector<pos> position;

double  kruskal(int k){
	double answer = 0;
	for(int i = 0 ; getSize() > k; i++){
		if(!isSameSet(edges[i].a.id,edges[i].b.id)){
			connect(edges[i].a.id,edges[i].b.id);
			answer = max(answer,edges[i].weight);
		}
	}
	return answer;
}

int main(){
	int n;
	int m,l;
	int x,y;
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++){
		edges.clear();
		position.clear();
		scanf("%d %d",&m,&l);
		initUni(l);
		for(int j = 0 ; j < l; j++){
			scanf("%d %d",&x,&y);
			position.push_back(pos(x,y,j));
		}
		for(int j = 0 ; j < l; j++)
			for(int k = j + 1; k < l; k++){
				edges.push_back(data(position[j],position[k]));
				}
		sort(edges.begin(),edges.end(),comp);	
		printf("%.2lf\n",kruskal(m));

	}

	return 0;
}

