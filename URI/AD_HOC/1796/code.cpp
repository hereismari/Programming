#include <stdio.h>

using namespace std;

int main() {

	int n;
	scanf("%d",&n);

	int x, quant_zeros = 0, quant_uns = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		if(x == 1) 
			quant_uns++;
		else 
			quant_zeros++;
	}
	
	if(quant_uns >= quant_zeros)
		printf("N\n");
	else
		printf("S\n");
}
