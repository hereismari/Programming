#include <stdio.h>

int eh_triangulo(int n, int m, int l){
	if ((n < m + l) && (m < n + l) && (l < n + m))
		return 1;
	else
		return 0;
}
int main(){
	
	int n,m,k,l;
	scanf("%d %d %d %d",&n,&m,&k,&l);
	
	if (eh_triangulo(n,m,k) || eh_triangulo(n,m,l) || eh_triangulo(n,k,l) || eh_triangulo(m,k,l))
		printf("S\n");
	else
		printf("N\n");
		
	return 0;
}
