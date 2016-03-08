#include <stdio.h>
#include <string.h>
#define MAX 1002

using namespace std;

int main(){

	int n;
	int k,c,need;
	int num;
	char x;
	scanf("%d",&n);
	
	for(int i = 0 ; i < n; i++){
		scanf("%d ",&k);
		c = need = 0;
		for(int j = 0 ; j < k+1 ; j++){
			scanf("%c",&x);
			num = x - '0';
			if(j > c){
				need += j -c;
				c += j -c;
			}
			c += num;
		}

	printf("Case #%d: %d\n",i+1,need);
	}
	return 0;
}
