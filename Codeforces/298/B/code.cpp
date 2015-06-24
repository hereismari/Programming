#include <stdio.h>
#include <math.h>

using namespace std;

int v1,v2,t,d;
int dist;
int val;

int acelera(){
	int a = d;
	while((v1 + a) - ((val-1)*d) > v2) a -= 1; 
//	printf("%d ", a);
	return a;
}

int main(){
	
	scanf("%d %d %d %d",&v1,&v2,&t,&d);
	dist = v1;
	val = t-1;
	while(t != 1){
		v1 += acelera();
//		printf(" %d",v1);
		dist += v1;
		t--;
		val--;
	}
	printf("%d\n",dist);
	return 0;
}
