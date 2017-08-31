#include <stdio.h>
#include <vector>
#include <map>
#define MAX 200001

using namespace std;

int n;
int k,p,m;
int cont;

vector <int> pset(MAX);
map < string , int > rel;
vector <int> nei(MAX);

void initSet(int _size) { for(int i = 0; i < _size*2 ; i++) pset[i] = i; }
void initNei(int _size) { for(int i = 0; i < _size*2 ; i++) nei[i] = 1; }

int findSet(int x) { return  (pset[x] == x) ? x : (pset[x] = findSet(pset[x])); }
bool isSameSet(int x,int y) { return findSet(x) == findSet(y); }
void unionSet(int x, int y) {if(!isSameSet(x,y)) {nei[findSet(y)] += nei[findSet(x)];  pset[findSet(x)] = findSet(y);}}
int sizeofSet(int x) { return nei[findSet(x)]; }

int main() {
	scanf("%d",&n);

	for(int i = 0 ; i < n ; i++){
		rel.clear();
		scanf("%d",&k);
		initSet(k);
		initNei(k);
		cont = 0;
		for(int j = 0 ; j < k ; j++) {
			scanf("%d %d"&m,&p);
			unionSet(m,p);
			printf("%d\n",sizeofSet(m));
		}
	}
	return 0;
}
