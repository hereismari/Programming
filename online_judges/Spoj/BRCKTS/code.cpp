#include <stdio.h>
#define MAX 311111

using namespace std;


struct data{
	bool v;
	int open,close;
	data(){};
	data(char c){
		close = open = 0;
		if (c == ')')
			close = 1;
		else
			open = 1;
		v = false;
	}

	data(data l,data r){

		if(l.v && r.v){ v = true; open = close = 0;}
		else if(!l.v && r.v){ v = false; open = l.open; close = l.close;}
		else if(l.v && !r.v){ v = false; open = r.open; close = r.close;}
		else{
			open = (l.open - r.close) < 0? 0: l.open - r.close; 
			open += r.open;
			close  = (r.close - l.open) < 0? 0: r.close - l.open; 
			close += l.close;
			if(open == 0 && close == 0) v = true;
			else v = false;
		}
	}
};

data t[4*MAX];

void build(int id, char a[], int b, int e){

	if( b == e) { t[id] = data(a[b]); return;}

	int m = (b+e)/2;
	build(2*id, a, b, m);
	build(2*id+1, a, m+1, e);

	t[id] = data(t[2*id],t[2*id+1]);
}
void update(int id, int b, int e, int pos, char val){

	if( b == e) { t[id] = data(val); return;}

	int m = (b+e)/2;
	if(pos <= m) update(2*id,b, m,pos,val);
	else update(2*id+1,m+1, e,pos,val);

	t[id] = data(t[2*id],t[2*id+1]);
}

data query(int id, int b, int e, int i, int j){

	if(i == b && j == e) return t[id];

	int m = (b+e)/2;
	
	if(j <= m) return query(2*id,b,m,i,j);
	if(i > m) return query(2*id+1,m+1,e,i,j);
	return data(query(2*id,b,m,i,m),query(2*id+1,m+1,e,m+1,j));

}

char a[MAX];

int main(){

	for(int j = 0 ; j < 10; j++){
	printf("Teste %d:\n",j+1);
	int n,m,x;
	scanf("%d",&n);
	for(int i = 1 ;  i <= n ; i++)
		scanf("\n%c",&a[i]);
	build(1,a,1,n+1);
	for(int i = 1; i <= 4*n ; i++)
		printf("%d ",t[i].v);
	scanf("%d",&m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d",&x);
		if(x == 0) {printf("%s\n",query(1,1,n+1,1,n+1).v? "YES":"NO");}
		else {
				char c = '(';
				if(a[x] == '(') c = ')';
				update(1,1,n+1,x,c);
		}

	}

}
	return 0;
}
