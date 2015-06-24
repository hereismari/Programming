#include <stdio.h>

using namespace std;

int main(){

	int a1,b1,a2,b2,a,b;

	scanf("%d %d %d %d %d %d",&a1,&b1,&a2,&b2,&a,&b);

	int area_possivel = (a1*b1) + (a2*b2);
	int area_lencol = a*b;

	printf("%c\n",area_possivel >= area_lencol ?'S':'N');

	return 0;
}
