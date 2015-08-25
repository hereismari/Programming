#include <stdio.h>
#include <algorithm>
#define MAX 1000000
#define ll long long int
#include <stdlib.h>

using namespace std;

struct data {
	int ballon;
};

data t[4*MAX];

data make_data(int val){
	data result;
	result.ballon = val;
	return result;
};

data combine(data l, data r){
	data result;
	result.ballon = max(l.ballon,r.ballon);
	return result;
}

void build(int id, int a[], int b, int e){

	if(b == e) {t[id] = make_data(a[b]); return;}

	int m = (b+e)/2;

	build(2*id, a, b,m);
	build(2*id + 1, a, m + 1, e);

	t[id] = combine(t[2*id],t[2*id + 1]);
};

void update(int id, int b, int e, int pos, int val){

	if(b == e) {t[id] = make_data(val); return; }

	int m = (b+e)/2;

	if(pos <= m)
		update(2*id,b,m,pos,val);
	else
		update(2*id + 1, m+1, e, pos,val);
	
	t[id] = combine(t[2*id],t[2*id + 1]);

}

data query(int id, int b, int e, int i, int j) {

	if(i == b && j == e) return t[id];

	int m = (b+e)/2;

	if(j <= m) return query(2*id,b,m,i,j);
	if(i > m) return query(2*id+1,m+1,e,i,j);
	return combine(query(2*id,b,m,i,m),query(2*id+1,m+1,e,m+1,j));
};

int p;
int n,m,k;
int a[MAX];
char c;
int x,y;

int main(){
	scanf("%d",&p);
	for(int j = 1 ; j <= p ; j++){
		printf("Testcase %d:\n", j-1);
		scanf("%d %d",&n,&m);
		for(int i = 1 ; i <= n ; i++)
			scanf("%d",&a[i]);
		build(1,a,1,n+1);
		scanf("%d",&k);
		for(int i = 0 ; i < k ; i++){
			scanf("\n%c", &c);
			if(c == 'B') { scanf("%d %d",&x,&y); update(1,1,n+1,x+1,y);}
			else if(c == 'A') { scanf("%d",&x); m += x;}
			else {
					scanf("%d %d",&x,&y);
					data res = query(1,1,n+1,x+1,y+1);
					printf("%d\n",abs(m-res.ballon));
			}
		}
		printf("\n");
	}
	return 0;
}
