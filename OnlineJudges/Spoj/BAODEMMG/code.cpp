#include <stdio.h>

using namespace std;

int n;
int t,x;
int answer;
int main(){

	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&t);
		answer = t*3;
		for(int j = 0 ; j < t; j++){
			scanf("%d",&x);
			answer -= 3*x;
		}

	if(answer < 0) printf("precisa\n");
	else printf("nao precisa\n");
}
	return 0;
}
