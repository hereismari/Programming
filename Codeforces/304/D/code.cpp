#include <bits/stdc++.h>
#define MAX 100000100
#define ll long long int

using namespace std;

ll answer[MAX];

ll primes(){

	for(int 2 = 0


}


int main(){

	int n;
	int a,b;
	scanf("%d",&n);

	primes();
	for(int i = 0  ; i < n ; i++){

		scanf("%d %d",&a,&b);
		printf("%lld\n",answer[a] - answer[b]);
	}

	return 0;
}
