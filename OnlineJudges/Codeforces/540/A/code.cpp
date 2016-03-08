#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int n;
char a1[MAX];
char a2[MAX];

int m(int a, int b){
	return min(abs(a-b),(10 - max(a,b) + min(a,b)));
}
int main(){

	scanf("%d",&n);
	for(int i = 0 ; i < n; i++)
		scanf("\n%c",&a1[i]);
	for(int i = 0 ; i < n; i++)
		scanf("\n%c",&a2[i]);
	int answer = 0;
	for(int i = 0 ; i < n; i++)
		answer += m(a1[i]-'0',a2[i]-'0');
	
	printf("%d\n",answer);
	return 0;
}
