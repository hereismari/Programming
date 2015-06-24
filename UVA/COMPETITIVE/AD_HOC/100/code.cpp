#include <bits/stdc++.h>

using namespace std;

int cycle(int n){

	int cont = 1;
	while(n != 1){
		if(n % 2 == 1) n = 3*n + 1;
		else n = n/2;
		cont++;
	}
	return cont;
}

int main(){

	int n,m;
	while(scanf("%d %d",&n,&m)){

		int answer = 0;
		for(int i = n; i <= m; i++)
			answer = max(answer,cycle(i));
		printf("%d %d %d\n",n,m,answer);

	}

	return 0;
}
