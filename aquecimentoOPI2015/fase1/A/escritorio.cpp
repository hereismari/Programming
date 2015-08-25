#include<stdio.h>
#include <string.h>
using namespace std;

int answer(int x) {

	int porta[x+1];
	memset(porta,0,sizeof porta);
	
	for(int i = 1; i <= x; i++)
		for(int j = i; j <= x; j += i)
			porta[j]++;
		
	int ans = 0;
	for(int i = 1; i <= x; i++)
		if(porta[i] % 2)
			ans++;
	return ans;
}


int main() {

	int n,x;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		printf("%d\n",answer(x));
	}

	return 0;
}
