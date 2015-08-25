#include <bits/stdc++.h>
#define MAX 100100

using namespace std;

struct data{
	int pass;
	data() {};
	data(int x){
		pass = x;
	}
	
	data(data l, data r){
		pass = l.pass + r.pass;
	}
};

int a[MAX];
data seg[4*MAX];

void build(int a[], int id, int b, int e){

	if(b == e) {seg[id] = data(a[b]); return;}
	
	int m = (b+e)/2;

	build(a,2*id,b,m);
	build(a,2*id+1,m+1,e);

	seg[id] = data(seg[2*id],seg[2*id+1]);
}

void update(int id, int b, int e, int pos, int val){

	
	if(b == e) {seg[id] = data(val); return;}

	int m = (b+e)/2;

	if(pos <= m) update(2*id,b,m,pos,val);
	else update(2*id+1,m+1,e,pos,val);

	seg[id] = data(seg[2*id],seg[2*id+1]);

}

data query(int id, int b, int e,int i, int j){

	if(i == b && j == e) return seg[id];

	int m = (b+e)/2;

	if(j <= m) return query(2*id,b,m,i,j);
	if(i > m) return query(2*id+1,m+1,e,i,j);

	return data(query(2*id,b,m,i,m),query(2*id+1,m+1,e,m+1,j));
}


int main(){
	int n;
	int x;
	char c;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&a[i]);
	}

	build(a,1,1,n + 1);
	while(scanf("\n%c %d",&c,&x) != EOF){
	if(c == 'a'){
			update(1,1,n+1,x,0);
		}
		else
			printf("%d\n",query(1,1,n+1,1,x-1).pass);
	}

	return 0;
}
