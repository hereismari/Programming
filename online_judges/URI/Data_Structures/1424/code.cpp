#include <bits/stdc++.h>
#define MAX 10000001

using namespace std;

int a[MAX];
map< pair<int,int>,int > answer;

int n,m;
int x,j;
int main(){

	while(scanf("%d %d",&m,&n)!=EOF){
	for(int i = 0; i < MAX; i++) a[i] = 0;
	for(int i = 0 ; i < m ; i++){
		scanf("%d",&x);
		a[x]++;
		answer[make_pair(x,a[x])] = i + 1;
	}
	
	for(int i = 0; i < n ; i++){
		scanf("%d %d",&j,&x);
		printf("%d\n",answer[make_pair(x,j)]);
	}
}
	return 0;
}
