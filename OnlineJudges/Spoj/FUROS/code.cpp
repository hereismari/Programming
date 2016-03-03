#include <bits/stdc++.h>
#define MAX 102000
#define ll long long int 

using namespace std;

struct ponto{
	int x,y;
	ponto(){};
	ponto(int x,int y){
		this->x = x;
		this->y = y;
	}
	ll dist(ponto o){
		return  2 * sqrt(pow(x-o.x,2) + pow(y-o.y,2));
	}

};

int main() {

	int n,x,y,cont=1;
	while(true)
	{
		scanf("%d",&n);
		if(n == 0) break;

		ponto a[n];
		for(int i = 0; i< n; i++){
			scanf("%d %d",&x,&y);
			a[i] = ponto(x,y);
		}

		ll answer[n] = {0};
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++){
				answer[i] = max(answer[i],a[i].dist(a[j]));
				answer[j] = max(answer[j],a[i].dist(a[j]));
		}
		
		ll final_answer = answer[0];
		for(int i = 0 ; i < n; i++)
			final_answer = min(final_answer,answer[i]);

		printf("Teste %d\n",cont++);
		printf("%lld\n\n",final_answer+6);
	}
	
	return 0;
}
