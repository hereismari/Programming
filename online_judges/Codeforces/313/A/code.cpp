#include <bits/stdc++.h> 

#define MAX 1002
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
int a[MAX];
int main() {
 
	scanf("%d",&n);
	int answer = 1;
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		if(x == 1) answer = -1;
	}
	
	printf("%d\n",answer);
	return 0; 
}
