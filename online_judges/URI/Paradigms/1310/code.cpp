#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;

int main() {

	while(scanf("%d",&n) != EOF) {

		int custo, r, j = 1;
		int answer = 0, aux = 0;
		scanf("%d",&custo);
		for(int i = 0; i < n ; i++){
			scanf("%d",&r);
			aux += r;
			aux -= custo;
			answer = max(answer,aux);
			if(aux < 0) aux = 0;
		}	

		printf("%d\n",answer);
	}	

	return 0; 
}
