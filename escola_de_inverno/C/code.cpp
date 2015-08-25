#include <stdio.h>
int  max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int main() {

	int ans = 0;
	int l1, l2, l3 ,l4;
	scanf("%d %d %d %d",&l1,&l2,&l3,&l4);
	ans = max(ans,min(min(l1,l3),l2+l4));
	ans = max(ans,min(min(l1,l4),l2+l3));
	ans = max(ans,min(min(l2,l3),l1+l4));
	ans = max(ans,min(min(l2,l4),l1+l3));

	printf("%d\n",ans*ans);
	return 0;

}
