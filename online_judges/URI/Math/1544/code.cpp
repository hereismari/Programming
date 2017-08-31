#include <stdio.h>
#include <algorithm>
#define MAX 20000001

using namespace std;

int a[MAX];

int answer(int x){
	if(a[x] != 0) return a[x];
	else {
		int c = x;
		while(c % 10 == 0) c = c/10;
		c = c % 10;
		int y = answer(x-1);
		return (((c*y) % 10 != 0) ? (c*y)%10 : ((c*y)/10) % 10);}
}

int main(){

	a[0] = 1; a[1] = 1; a[2] = 2; a[3] = 6; a[4] = 4;
	int n, m;
	while(scanf("%d %d",&n,&m)!=EOF){

		int x =answer(n);
		int y = answer(m);
		x *= 10;
		y *= 10;
//		printf("%d %d\n",x,y);
		if (n == m) printf("%d\n", x/10);
		else printf("%d\n", max(x/y,y/x));

	}

	return 0;
}
