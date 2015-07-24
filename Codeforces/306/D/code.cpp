#include <bits/stdc++.h> 

#define MAX 1010 
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
vi adj[MAX];

int main() {
 
	scanf("%d",&n);
	if(n % 2 == 0) {printf("NO\n"); return 0;}
		
	printf("YES\n");
	if(n == 1){
		printf("2 1\n1 2\n"); return 0;
	}

	printf("%d %d\n",(n+2)*2, ((( (n+1)*n)/2) + (n-1)/2)*2 + 1);
	int aux = 0;
	int cont = 0;

	adj[1].pb(2);
	for(int i = 2; i < n + 1; i++){
		adj[1].pb(2*i - 1);
		//adj[2*i -1].pb(1);
		
		adj[2].pb(2*i);
		//adj[2*i].pb(2);
		
	}

	for(int i = 2; i <= n + 2; i++){
		for(int j = i+1; j <= n + 2; j++){
				if(i != j){
					if(i >= n+1){
						adj[2*i - 1].pb(2*j - 1);
					//	adj[2*j - 1].pb(2*i - 1);
					
						adj[2*i].pb(2*j);
					//	adj[2*j].pb(2*i);	
					}
					else if(aux % 2 == 0 && j != i+1){
						adj[2*i - 1].pb(2*j - 1);
					//	adj[2*j - 1].pb(2*i - 1);
					
						adj[2*i].pb(2*j);
					//	adj[2*j].pb(2*i);
					}
					else if(aux % 2 == 1 && j != i-1){
						adj[2*i - 1].pb(2*j - 1);
					//	adj[2*j -1].pb(2*i -1);
					
						adj[2*i].pb(2*j);
					//	adj[2*j].pb(2*i);
					}
				}
			}
			aux++;
		} 

	for(int i = 1; i <= (n+2)*2; i++){
		for(int j = 0; j < adj[i].size(); j++)
			printf("%d %d\n",i,adj[i][j]);
	}
	return 0; 
}
