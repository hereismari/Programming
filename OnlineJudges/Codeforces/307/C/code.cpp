#include <bits/stdc++.h>
#define MAX 100000
#define MAX_VALUE 2000000
#define ll long long int 
using namespace std;

int n,m;
ll s;
int a[MAX];

bool possible(ll time){

	int last_index = n-1;
	int aux[MAX];

	for(int i = 0 ; i < n ; i++)
		aux[i] = a[i];

	for(int i = 0; i < m; i++){

		while(last_index >= 0 && aux[last_index] == 0)
			last_index--;

		ll aux_time = time - last_index - 1;
		if(aux_time <= 0) break;

		while(last_index >= 0 && aux[last_index] <= aux_time)
			aux_time -= aux[last_index--]; 
	
		if(last_index >= 0) aux[last_index] -= aux_time;

	}

	return last_index <  0;
}

ll binSearch(){

	ll l = 2;
	ll r = s + n;
	ll m = (r+l) /2;
	while(l < r) {
		if(possible(m)) r = m;
		else l = m + 1;

		m = (l + r)/2;
	}

	return r;
}

int main(){

	scanf("%d %d",&n,&m);
	s = 0;
	for(int i = 0; i < n ; i++){
		scanf("%d",&a[i]);
		s += a[i];
	}

	printf("%lld\n", binSearch());

	return 0;
}
