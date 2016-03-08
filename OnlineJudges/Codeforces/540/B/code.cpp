#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int a[MAX+1];
int visit[MAX + 1] = {0};

int main(){

	int n,k,p,x,y;
	scanf("%d %d %d %d %d",&n,&k,&p,&x,&y);
	a[0] = -1;
	int sum = 0;
	for(int i = 1 ; i <= k; i++){
		scanf("%d",&a[i]);
		visit[a[i]]++;
	}

	for(int i = k+1; i <= n; i++) {a[i] = 1;}
	sort(a,a+n+1);	
	int median = (n+1)/2;
	
	while(a[median] < y) {a[1] += a[median]; sort(a,a+n+1);}
	for(int i = 1; i <= n; i++) sum += a[i];
	if(sum > x) { printf("-1\n");return 0;}
	
	for(int i = 1; i <= n; i++){
		if(visit[a[i]] <= 0) printf("%d ",a[i]);
		visit[a[i]]--;}
	printf("\n");

	return 0;
}
