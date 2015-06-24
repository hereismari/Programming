#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

int a[MAX];

int binsearch(int x, int n){

	int i = 0;
	int f = n-1;
	int answer = -1;

	while(i <= f){
		int m = (i+f)/2;
		if(a[m] == x) { answer = m; f = m -1;}
		else if(a[m] > x) f = m-1;
		else i = m+1;
	}
	
	return answer;
}

int main(){

	int n,k,x;
	int cont = 1;
	while(1){
		scanf("%d %d",&n,&k);
		if(n == 0 && k == 0) break;
		for(int i = 0 ; i < n; i++) scanf("%d",&a[i]);
		sort(a,a+n);
		
		printf("CASE# %d:\n",cont++);
		for(int i = 0 ; i < k; i++) {
			scanf("%d",&x); 
			int answer = binsearch(x,n); 
			if(answer != -1) printf("%d found at %d\n",x,answer + 1);
			else printf("%d not found\n",x);
		}
	}
	return 0;
}
