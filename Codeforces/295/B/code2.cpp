#include <bits/stdc++.h>
#define MAX 500000
#define F first
#define S second

using namespace std;
int n, m;
bool visited[MAX];

int answer(int x) {

	int cont = 0;

	while(x > n){
		if ( x % 2 == 0)
			x = x/2;
		else
			x += 1;
		cont++;
	}

	return cont + n - x;
}

int main(){

	scanf("%d %d",&n,&m);
	printf("%d\n",answer(m));
	return 0;
}
