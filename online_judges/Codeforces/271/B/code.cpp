#include <stdio.h>

int posicoes[100002];
int n;

int buscaBinaria(int x) {
	
	int e = 0, d = n-1;
	
	while (e <= d) { 
		int m = d + (e - d)/2; 
        printf("%d %d\n", x, m);
        if (posicoes[m] < x ) e = m + 1;
		else if (posicoes[m] > x) d = m - 1;
		else return m;
	}
	
	return d + 1;
}
        
int main() {
	
    int m, x, cont = 0;
    int copia;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d",&x);
        cont += x;
		posicoes[i] = cont;
    }

    scanf("%d", &m);
    
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        printf("%d\n", buscaBinaria(x) + 1);
    }
    
    return 0;
}
