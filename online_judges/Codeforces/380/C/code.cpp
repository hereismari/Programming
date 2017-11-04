#include <bits/stdc++.h>

#define MAX 1000020
#define ll long long int
using namespace std;

struct data {
	int v;
  int l, r;
};

data t[4*MAX];

data make_data(char c) {
	data result;
	result.v = 0;
  result.l = (c == '(');
  result.r = (c == ')');
	return result;
}

data combine(data x, data y) {
	
	data result;
  
  int v = min(x.l, y.r);
  result.v = x.v + y.v + v;
  result.l = x.l + y.l - v;
  result.r = x.r + y.r - v;
	return result;
}

void build(int id, char s[], int b, int e){

	if(b == e) { t[id] = make_data(s[b-1]); return;}

	int m = (b+e)/2;

	build(2*id, s, b, m);
	build(2*id + 1, s, m + 1, e);

	t[id] = combine(t[2*id], t[2*id + 1]);
};
/*
void update(int id, int b, int e, int pos, int val){

	if(b == e) {
	  t[id] = make_data(val);
	  return;
  }

	int m = (b+e)/2;

	if(pos <= m)
		update(2*id,b,m,pos,val);
	else
		update(2*id + 1, m+1, e, pos,val);
	
	t[id] = combine(t[2*id],t[2*id + 1]);
}*/

data query(int id, int b, int e, int i, int j) {

	if(i == b && j == e) return t[id];

	int m = (b+e)/2;

	if(j <= m) return query(2*id,b,m,i,j);
	if(i > m) return query(2*id+1,m+1,e,i,j);
	return combine(query(2*id,b,m,i,m),query(2*id+1,m+1,e,m+1,j));
};

int x, y;
char c;

int main() {

  char s[MAX];
  scanf ("%s", s);

  int m, n = strlen(s);

	build(1, s, 1, n+1);

  int q;
  scanf("%d", &q);
	for(int i = 0 ; i < q; i++){
		scanf("%d %d", &x, &y);
		int v = query(1, 1, n+1, x, y).v;
		printf("%d\n", v * 2);
	}

  return 0;
}
