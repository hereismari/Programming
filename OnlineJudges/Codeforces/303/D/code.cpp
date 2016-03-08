#include <bits/stdc++.h>
#define MAX 100010
#define ll long long int

using namespace std;

int main(){
	
	int n;
	ll v[MAX];
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++)
		scanf("%lld",&v[i]);

	sort(v,v+n);
	int answer = 1;
	int cont = v[0];
	for(int i = 1; i < n; i++){
		if(cont <= v[i]){
			answer += 1;
			cont += v[i];
		}
	}
	printf("%d\n",answer);

}
