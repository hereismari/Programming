#include <stdio.h>
#define MAX 50002
#define INF 1000000000
#define ll long long int

using namespace std;

ll b[MAX];
ll h[MAX];
ll w[MAX];
ll d[MAX];

int v;
int k;
int n;

double bin_search(){

	double low = 0;
	double high = INF;
	double vol = 0;
	double level = 0;
	while(high - low > 0.000001){

		level = (high + low)/2;
		vol = 0;
	
		for(int i = 0 ; i < n ; i++){
			if(b[i] >= level) continue;
			else if(b[i] < level && b[i] + h[i] >= level) vol += (level-b[i])*w[i]*d[i];
			else if(b[i] + h[i] < level) vol += h[i]*w[i]*d[i];
		}

		if(vol >= v) 
			high = level;
		else
			low = level;
	}

	return level;
}

int main(){
	
	double vol = 0;
	
	scanf("%d",&k);
	for(int i = 0 ; i < k ; i++){
		vol = 0;	
		scanf("%d",&n);
		for(int j = 0; j < n ; j++){
			scanf("%lld %lld %lld %lld",&b[j],&h[j],&w[j],&d[j]);
			vol += h[j]*w[j]*d[j];
		}
		scanf("%d",&v);
		if(v > vol) printf("OVERFLOW\n");
		else printf("%.2f\n",bin_search());
	}

	return 0;
}
