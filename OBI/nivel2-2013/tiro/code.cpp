#include <stdio.h>
#include <math.h>
#define ll long long int
#define MAX 1000001

using namespace std;

ll bin_search(ll v[MAX], ll x, ll lim){
	
	ll i = 0;
	ll j = lim-1;
	ll m = (i+j)/2;
	if(x > v[lim-1]) return 0;
	while(i < j){
		if(v[m] < x) i = m + 1; 
		else if(v[m] >= x) j = m;
		m = (i+j)/2;
	}

	return (lim-j);
}

int main(){

	ll c,t;
	ll alvos[MAX];
	ll x,y,tiro;
	ll pontuacao = 0;

	scanf("%lld %lld",&c,&t);
	for(int i = 0; i < c ; i++){
		scanf("%lld",&alvos[i]);
		alvos[i] *= alvos[i];
	}

	for(int j = 0; j < t ; j++){
		scanf("%lld %lld",&x,&y);
		tiro = pow(x,2) + pow(y,2);
		pontuacao += bin_search(alvos,tiro,c);
	}

	printf("%lld\n",pontuacao);
	return 0;

}
