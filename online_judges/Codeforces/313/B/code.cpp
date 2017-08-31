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

int n,m,x[2],y[2];

bool put(int a, int b, int x1, int x2,int y1,int y2){
	return a >= x1 + x2 && b >= max(y1,y2);
}

int main() {
	int a,b; 
	scanf("%d %d",&a,&b);
	scanf("%d %d",&x[0],&x[1]);
	scanf("%d %d",&y[0],&y[1]);

	if(put(a,b,x[0],y[0],x[1],y[1]))
		{ printf("YES\n"); return 0;}
	
	if(put(a,b,x[1],y[0],x[0],y[1]))
		{ printf("YES\n"); return 0;}
	
	if(put(a,b,x[0],y[1],x[1],y[0]))
		{ printf("YES\n"); return 0;}
	
	if(put(a,b,x[1],y[1],x[0],y[0]))
		{ printf("YES\n"); return 0;}
	
	if(put(b,a,x[0],y[0],x[1],y[1]))
		{ printf("YES\n"); return 0;}
	
	if(put(b,a,x[1],y[0],x[0],y[1]))
		{ printf("YES\n"); return 0;}
	
	if(put(b,a,x[0],y[1],x[1],y[0]))
		{ printf("YES\n"); return 0;}
	
	if(put(b,a,x[1],y[1],x[0],y[0]))
		{ printf("YES\n"); return 0;}
	
	printf("NO\n");
	return 0; 
}
