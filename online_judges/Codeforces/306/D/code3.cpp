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
	
    // the vertices of the bridge will have an odd degree 
    if(n % 2 == 0) { printf("NO\n"); return 0; }
		
	printf("YES\n");

    // special case
	if(n == 1) {
		printf("2 1\n1 2\n"); return 0;
	}

    // number of vertices = (number of vertices
    // in the strong connected component of degree n) + 1 = (n+2) 

    // number of edges = 
	printf("%d %d\n",(n + 1) * 2, n * (n + 1));
    
    // creating bridges
	adj[1].pb(2);
    adj[(n+1) * 2 -1].pb((n+1) * 2);

	for(int i = 1; i <= n + 1; i++) {
		for(int j = i+1; j <= n + 1; j++) {
		    if(i != j) {
		        if(i == 1 && j == n + 1) continue;
                adj[i*2 -1].pb(j*2 - 1);
                adj[i*2].pb(j*2);
            }
		}
    } 

	for(int i = 1; i <= (n+1)*2; i++){
		for(int j = 0; j < adj[i].size(); j++)
			printf("%d %d\n",i,adj[i][j]);
	}
	return 0; 
}
