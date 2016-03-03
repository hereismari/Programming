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
int a[4];
bool flag;

void verify(){

	if(n == 0) {  
		a[0] = a[1] = 1;
		a[2] = a[3] = 3;
	}
	if(n == 1){
		a[1] = a[2] = a[0]; a[3] = a[0]*2;
	}
	else if(n == 2){
			
	}
	else if(n == 3){

	}
	else{

	}

}

int main() {
	flag = true;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	sort(a,a+n);
	if(flag) 
		{printf("YES\n"); for(int i = n; i < 4; i++) printf("%d\n",a[i]);}
	else printf("NO\n");

	return 0; 
}
