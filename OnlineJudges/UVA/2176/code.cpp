#include <stdio.h>
#include <algorithm>
#define MAX 1000000
#define ll long long int
#include <stdlib.h>
#define max(a,b)(a < b ? b : a)

using namespace std;

struct data{
	int val,freq;	
	data(int x=0,int y=1){
		val = x;
		freq = y;
	}
};

data operator+(const data &l, const data &r){
	if(l.val != r.val)
		return data(0,0);
	return data(l.val,l.freq + r.freq);
}

bool operator<(const data &l, const data &r){
	return l.freq < r.freq;
}

struct node{
	data left,right,answer;
	
	node(int val) {
		left = right = answer = data(val);
	}
	
	node(){};
	
	node(node l,node r){
		left = max(l.left, l.left + r.left);
		right = max(r.right, l.right + r.right);
		answer = max(l.answer,max(r.answer,l.right + r.left));
	}
	
};

node t[4*MAX];

void build(int id, int a[], int b, int e){

	if(b == e) {t[id] = node(a[b]); return;}

	int m = (b+e)/2;

	build(2*id, a, b,m);
	build(2*id + 1, a, m + 1, e);
	t[id] = node(t[2*id],t[2*id+1]);

};

void update(int id, int b, int e, int pos, int val){

	if(b == e) {t[id] = node(val); return; }

	int m = (b+e)/2;

	if(pos <= m)
		update(2*id,b,m,pos,val);
	else
		update(2*id + 1, m+1, e, pos,val);
	
	t[id] = node(t[2*id],t[2*id+1]);

}

node query(int id, int b, int e, int i, int j) {

	if(i == b && j == e) return t[id];

	int m = (b+e)/2;

	if(j <= m) return query(2*id,b,m,i,j);
	if(i > m) return query(2*id+1,m+1,e,i,j);
	return node(query(2*id,b,m,i,m),query(2*id+1,m+1,e,m+1,j));
};

int p;
int n,m,k;
int a[MAX];
char c;
int x,y;

int main(){
	while(1){
	scanf("%d",&n);
	if(n == 0) break;
	scanf("%d",&m);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	build(1,a,1,n+1);
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",query(1,1,n+1,x,y).answer.freq);

	}
}
	return 0;
}
