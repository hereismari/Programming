#include <bits/stdc++.h>
#define MAX 10000

using namespace std;

int g[MAX];
int aux[MAX];
int n;

bool ready(){
	for(int i = 0 ; i < n ; i++)
		if(i != g[i]) return false;
	return true;
}

bool theSame(){
	for(int i = 0 ; i < n ; i++)
		if(aux[i] != g[i]) return false;
	return true;
}

void changeIt(){
	for(int i = 0 ; i < n; i++){
		if(i % 2 == 0)
			g[i] += 1;
		if(i % 2 == 1)
			g[i] -= 1;

		if(g[i] >= n ) g[i] = 0;
		else if(g[i] < 0) g[i] = n-1;
	}
}

int main(){

	scanf("%d",&n);

	for(int i = 0 ; i < n ; i++){
		scanf("%d",&g[i]);
		aux[i] = g[i];
	}

	while(true){

		changeIt();
		if(ready()) { printf("Yes"); return 0;}
		else if (theSame()) { printf("No"); return 0;}

	}
	return 0;
}
