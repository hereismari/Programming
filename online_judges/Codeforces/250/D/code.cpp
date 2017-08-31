#include <bits/stdc++.h>
#define MAX 100010
#define pb push_back
#define ll long long int
using namespace std;

struct edge{
	
	int a, b, w;
	edge(int a=0,int b=0, int w=0){
		this->a=a;
		this->b=b;
		this->w=w;
	}

};

bool comp(edge a, edge b){
	return a.w > b.w;
}

int n,m,x,y;
int a[MAX];
edge path[MAX];
int uni[MAX];
int size[MAX];
int rank[MAX];
double answer;

void initSet() { for(int i = 0; i < MAX; i++) {uni[i] = i; size[i] = 1;rank[i] = 0;}}
int findSet(int x) { return (x == uni[x]) ? x : findSet(uni[x]); }
bool isSameSet(int x, int y) {return findSet(x) == findSet(y);}
int sizeUni(int x) {return size[findSet(x)];}
void connect(int x, int y, int w) { 
	int par_x = findSet(x);
	int par_y = findSet(y);
	answer += (double)w * sizeUni(par_x) * sizeUni(par_y);
	if(rank[par_x] < rank[par_y]) {
        uni[par_x] = par_y;
		size[par_y] += size[par_x];
    }
    else if (rank[par_x] > rank[par_y]) {
        uni[par_y] = par_x;
        size[par_x] += size[par_y];
    }
    else {
        uni[par_y] = par_x;
        rank[par_x]++;
        size[par_x] += size[par_y];
    }
}


void kruskall(){

	initSet();
	answer = 0;
	sort(path,path+m,comp);
	for(int i = 0; i < m; i++){
		if(!isSameSet(path[i].a,path[i].b))
			connect(path[i].a,path[i].b,path[i].w);
		
	}
}

int main() {

	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	for(int i = 0; i < m; i++){
		scanf("%d %d",&x ,&y); 
		path[i] = (edge(x,y,min(a[x],a[y])));}

	kruskall();
//	printf("%lld\n",answer);
	printf("%.6lf\n",2.0*answer/(1.0*n*(n-1)));
	return 0;
}
