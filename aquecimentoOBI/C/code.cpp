#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	scanf("%d",&n);
	int count1 = 0;
	int count0 = 0;

	for(int i = 0 ; i < n; i++){
		scanf("%d",&x);
		if(x == 1) count1++;
		else count0++;
	}

	printf("%c\n",(count0>count1)?'Y':'N');

    return 0;
}
