#include <stdio.h>
#include <vector>
#include <utility> 
#include <string.h>
#include <algorithm>
#define ll long long
#define ppi pair<int, int>
#define MAX 100000

using namespace std;

int t;
int n,c;
vector< pair<int,int> > calcada(MAX);
int e,x,a,b;

int cont;

int bin_search(int k, int _size){
	
	int b = 0;
	int e = _size;
	int m = _size/2;

	while(b <= e){
		if(calcada[m].first <= k && calcada[m].second >= k) return 1;
		else if(calcada[m].first > k) e = m-1;
		else b = m+1;
		m = (b + e)/2;
	}
	return 0;
}

int main(){
	
	scanf("%d",&t);
	for(int i = 0 ; i < t ; i++){
		scanf("%d %d",&n,&c);
		for(int j = 0 ; j < c ; j++){
			scanf("%d %d",&a,&b);
			calcada[j] = make_pair(a,b);
		}
		sort(calcada.begin(),calcada.begin() + c);

		cont = 0;
		scanf("%d",&e);

		for(int j = 0 ; j < e ; j++)
		{
			scanf("%d",&x);
			cont += bin_search(x,c);
		}

		printf("Caso #%d: %d\n",i+1,cont);
	}

	return 0;
}
