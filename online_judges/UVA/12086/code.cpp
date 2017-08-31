#include <stdio.h>
#include <string.h>
#define MAX 300000
#define INF 1100
#define ll long long int

using namespace std;

struct data{
	ll resistance;
};

data seg[4*MAX];

data make_data(ll val){
	data result;
	result.resistance = val;
	return result;
}

data combine(data l, data r){
	data result;
	result.resistance = l.resistance + r.resistance;
	return result;
}

void build(int id,int a[], int b, int e){

	if(b == e) seg[id] = make_data(a[b]);
	else{
		
		int m = (b+e)/2;
		build(2*id, a, b, m);
		build(2*id+1, a, m+1, e);
		seg[id] = combine(seg[2*id],seg[2*id+1]);
	}

}

void update(int id, int b, int e, int pos, int val){

	if(b == e) seg[id] = make_data(val);
	else{
		int m = (b+e)/2;
		if(pos <= m) update(2*id,b,m,pos,val);
		else update(2*id + 1,m + 1,e,pos,val);

		seg[id] = combine(seg[2*id],seg[2*id + 1]);
	}
}

data query (int id, int b, int e, int i, int j) {
	if (b == i && e == j)
		return seg[id];
	int m = (b + e) / 2;
	if (j <= m)
		return query (id*2, b, m, i, j);
	if (i > m)
		return query (id*2+1, m+1, e, i, j);
	return combine (
		query (id*2, b, m, i, m),
		query (id*2+1, m+1, e, m+1, j)
	);
}


int n;
int a[MAX];
char s[10];
int x,y;

int main(){
	int j = 1;
	scanf("%d",&n);
	if(n == 0) return 0;
	while(1){
		printf("Case %d:\n",j++);
		for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
		build(1,a,1,n+1);
		scanf("\n%s",s);
		while(strcmp(s,"END") != 0){

			scanf("%d %d",&x,&y);
			if(strcmp(s,"M") == 0) {
				data answer = query(1,1,n+1,x,y);
				printf("%lld\n",answer.resistance);
			}
			else update(1,1,n+1,x,y);
			scanf("\n%s",s);
		}
		
		scanf("%d",&n);
		if(n == 0) break;
		printf("\n");
	}

	return 0;
}
