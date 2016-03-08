#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) (a < b ? a : b)
#define MAX_VALUE 101
#define MAX_OBJECTS 1001

using namespace std;

const int INF = 0x3f3f3f3f;

int c;
int t,a;
int k;
int cs;
int o,n,w;

int m[MAX_OBJECTS][MAX_VALUE][MAX_VALUE];
int fl[MAX_OBJECTS][MAX_VALUE][MAX_VALUE];

typedef struct object{int quant_o, quant_n, weight;} sack;
sack ob[MAX_OBJECTS];

int knap(int i, int co, int cn) {

	if(co >= t && cn >= a) return 0; if(i == k) return INF;
	if(co >= t) co = t; if(cn >= a) cn = a;
	if(fl[i][co][cn] == cs) return m[i][co][cn]; fl[i][co][cn] = cs;
	return m[i][co][cn] = min(knap(i+1, co, cn), knap(i+1, co + ob[i].quant_o, cn + ob[i].quant_n) + ob[i].weight);

}

int main(){

	scanf("%d",&c);
	for(cs = 1 ; cs <= c ; cs++){
		scanf("%d %d",&t,&a);
		scanf("%d",&k);
		int j;
		for(j = 0 ; j < k ; j++){
			scanf("%d %d %d",&o,&n,&w);
			ob[j].quant_o = o;
			ob[j].quant_n = n;
			ob[j].weight = w;
		}

		printf("%d\n",knap(0,0,0));
	}
	return 0;
}
