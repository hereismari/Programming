#include <bits/stdc++.h>
#define MAX 100100
#define ll long long int
using namespace std;

int tree[MAX], a[MAX], n;

void update(int pos, int val){
	while(pos <= n) {
		tree[pos] += val;
		pos += (pos & -pos);
	}
}

int query(int pos){
	int ans = 0;
	while(pos >= 1) {
		ans += tree[pos];
		pos -= (pos & -pos);
	}
		
	return ans;
}


int main(){

	int x;
	char c;
	memset(tree, 0, sizeof tree);
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&a[i]);
		update(i,a[i]);
	}

	while(scanf("\n%c %d",&c,&x) != EOF){
	if(c == 'a'){
			update(x, -a[x]);
		}
		else
			printf("%d\n",query(x-1));
	}

	return 0;
}
