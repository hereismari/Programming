#include <bits/stdc++.h>

#define MAX 300000
#define ll long long int
#define MOD 1000000007
using namespace std;

struct data {
	vector<int> elements;
};

data t[4 * MAX + 10];

int n, k, q;
int a[MAX + 10];
int x, y;

ll get_multi(const vector<int> &v) {
  
  if(v.size() == 0) return 0;
  
  ll res = 1;
  for(int i = 0; i < v.size(); i++) res = (res * v[i]) % MOD;
  
  return res;
}

data make_data(int val) {
	data result;
	result.elements.push_back(val);
	return result;
};

data combine(data l, data r){
	data result;
	
	vector<int> v;
	int i = 0, j = 0;
	int r_size = r.elements.size();
	int l_size = l.elements.size();
	while(v.size() < k && (i < l_size || j < r_size)) {
	  if(i >= l_size && j < r_size) { 
	    if(r.elements[j] > 0) v.push_back(r.elements[j]); 
	    j++;
	  } 
	  else if(j >= r_size && i < l_size) { 
	    if(l.elements[i] > 0) v.push_back(l.elements[i]); 
	    i++;
	  } 
	  else if(l.elements[i] > r.elements[j]) {
	    if(l.elements[i] > 0) v.push_back(l.elements[i]);
	    i++;
	  }
	  else {
	    if(r.elements[j] > 0) v.push_back(r.elements[j]); 
	    j++;
	  }  
	}
	
	result.elements = v;
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

int main() {
	
	scanf("%d %d %d", &n, &k, &q);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	build(1, a, 1, n+1);
	
	for(int i = 0 ; i < q; i++) {
	  scanf("%d %d", &x, &y);
		data res = query(1, 1, n + 1, x, y);
		printf("%lld\n", get_multi(res.elements));
  }
  
	return 0;
}
