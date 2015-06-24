#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){

	int i12,i23;
	int b[3];
	scanf("%d %d %d",&b[0],&b[1],&b[2]);
	sort(b,b +3);
	
	i12 = (b[0] + 200 -b[1]) >= 0 ? (b[0] + 200 - b[1]): 0;
	i23 = (b[1] + 200 -b[2]) >= 0 ? (b[1] + 200 - b[2]): 0;
	printf("%d\n", (i12 + i23)*100);
	return 0;
}
