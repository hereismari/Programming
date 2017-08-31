#include <bits/stdc++.h>

using namespace std;

#define MAX 9

struct data {
	
	int index, value, comparing_value;
	
	data(int v = 0, int id = 0, int n = 0) {
		value = v;
		index = id;
		comparing_value = n / v;
	}
	
	bool operator < (const data &d) const {
		if(comparing_value != d.comparing_value) 
			return comparing_value > d.comparing_value;
		else 
			return index > d.index;
	}
};


int main() {

	int n;
	scanf("%d", &n);
	
	data v[MAX];
	int a[MAX];
	
	for(int i = 0; i < MAX; i++) {
		scanf("%d", &a[i]);
		v[i] = data(a[i], i, n);
	}

	sort(v, v + MAX);
	
	set<pair<int, int> > s;
	
	int ans[MAX]; memset(ans, 0, sizeof ans);
	
	int len = v[0].comparing_value;
	int remaining = n - (v[0].value * len);
	
	ans[v[0].index] = len; 
	
	//for(int i = 0; i < MAX; i++) printf("%d ", v[i].comparing_value);
	
	if(len == 0) { printf("-1"); return 0;}
	
	for(int i = 0; i < len; i++) {
		int new_number = v[0].index;
		for(int j = MAX-1; j >= 0; j--) {
			if(j > new_number && a[j] <= remaining + v[0].value) {
				new_number = j;
			}
		}
		
		remaining = remaining + v[0].value - a[new_number];
		ans[new_number]++;
		ans[v[0].index]--;
	}

	for(int i = MAX-1; i >= 0; i--) {
		while(ans[i]--) printf("%d", i+1);
	}
	
	
	return 0;
}
