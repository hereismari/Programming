#include <bits/stdc++.h>

#define MAX 1000000
#define ll long long int
using namespace std;

struct data {
	int v;
};

data t[4*MAX];

data make_data(int val) {
	data result;
	result.v = val;
	return result;
}

int gcd(int x, int y) {
  return ((y == 0) ? x : gcd(y, x % y));
}

data combine(data l, data r) {
	data result;
	
	result.v = gcd(l.v, r.v);
	return result;
}

void build(int id, int b, int e){

	if(b == e) {t[id] = make_data(0); return;}

	int m = (b+e)/2;

	build(2*id, b, m);
	build(2*id + 1, m + 1, e);

	t[id] = combine(t[2*id], t[2*id + 1]);
};

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
}

data query(int id, int b, int e, int i, int j) {

	if(i == b && j == e) return t[id];

	int m = (b+e)/2;

	if(j <= m) return query(2*id,b,m,i,j);
	if(i > m) return query(2*id+1,m+1,e,i,j);
	return combine(query(2*id,b,m,i,m),query(2*id+1,m+1,e,m+1,j));
};

int n, x;
int a[MAX];
char c;

int main() {
	int n;
	scanf("%d", &n);
	build(1, 1, n + 1);
	
	int last_element = 1;
	multimap<int, int> m;
	 
	for(int i = 0 ; i < n; i++){
		scanf("\n%c %d", &c, &x);
		if(c == '+') {
		  update(1, 1, n+1, last_element, x);
		  m.insert(make_pair(x, last_element++));
		}
		else {
		  multimap<int,int>::iterator it = m.find(x);
		  update(1, 1, n+1, it->second, 0);
      m.erase(it);
		}
		int v = query(1, 1, n+1, 1, n+1).v;
		if (v == 0) v = 1;
		printf("%d\n", v);
	}

  return 0;
}
