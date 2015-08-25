#include <stdio.h>
#include <algorithm>
#include <climits>
using namespace std;

int main() {

	int n;
	scanf("%d",&n);
	int x[n],y[n];
	int min_x,min_y,max_x,max_y;


	min_x = min_y = INT_MAX;
	max_x = max_y = 0;
	for(int i = 0; i < n; i++){
		scanf("%d %d",&x[i],&y[i]);
		min_x = min(x[i],min_x);
		min_y = min(y[i],min_y);
		max_x = max(x[i],max_x);
		max_y = max(y[i],max_y);
	}
	
	int lado = max(max_y-min_y,max_x-min_x);
	printf("%d\n",lado*lado);

	return 0;
}
