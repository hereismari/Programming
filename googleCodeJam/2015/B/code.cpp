#include <stdio.h>
#include <math.h>
#include <algorithm>

#define MAX 1002

using namespace std;

int n,k;
int num;
int array[MAX];
int normal[MAX];

int minor_value(int x){
	int m;
	m = 1 + ceil(x/2.0);
	int cont = 1;
	int x1 = x;
	int x2 = x;
	while(m < x1){
		cont++;
		x1 = m;
		x2 = ceil(x2/2.0);
//		printf("%d ",m);
		m = pow(2,cont) + ceil(x2/2.0) -1;
	}
	return x2;
}

int minor_sum(int x){
	int m;
	m = 1 + ceil(x/2.0);
	int cont = 1;
	int x1 = x;
	int x2 = x;
	int sum = 0;
	while(m < x1){
		sum = pow(2,cont) - 1;
		cont++;
		x1 = m;
		x2 = ceil(x2/2.0);
//		printf("%d ",m);
		m = pow(2,cont) + ceil(x2/2.0) -1;
	}
	return sum;
}
int main() {
	int soma;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&k);
		for(int j = 0 ; j < k ; j++){
			scanf("%d",&num);
			normal[j] = num;
			array[j] = minor_value(num);
		}
		int max_value = array[k-1]; + minor_sum(normal[k-1]);
		int place = array[k-1];
		for(int j = k-2 ; j >=0 ; j--){
			if(normal[j] > place){
			//	printf("oi");
				if((max_value + minor_sum(normal[j])) > normal[j]){
					max_value = normal[j];
					place = normal[j];}
				else{
					printf("%d %d ",minor_sum(normal[j]),max_value);
					max_value += minor_sum(normal[j]);
				}
			}
		}

		printf("Case #%d: %d\n",i+1,max_value);
	}

	return 0;
}
