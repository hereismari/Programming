#include <bits/stdc++.h>

using namespace std;

bool winner(int w,int l1,int l2){
	return w != l1 && l1 == l2;
}

int main() {

	int a,b,c;
	while(scanf("%d %d %d",&a,&b,&c) != EOF) {

	if(winner(a,b,c))
		printf("A\n");
	else if(winner(b,a,c))
		printf("B\n");
	else if(winner(c,a,b))
		printf("C\n");
	else
		printf("*\n");

	}
	return 0;
}
