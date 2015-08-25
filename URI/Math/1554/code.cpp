#include <bits/stdc++.h>
 
int main() {
 
    int n, x, y, x1, y1, c, numero, bolaMaisProxima;
    double res, menor;
    scanf("%d", &c);
    while(c--)
    {
        numero = 0;
        scanf("%d", &n);
        scanf("%d %d", &x, &y);
        scanf("%d %d", &x1, &y1);
        menor = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
        bolaMaisProxima = ++numero;
        while(n-1)
        {
            scanf("%d %d", &x1, &y1);
            res = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
            ++numero;
            if(res < menor - 0.01)
            {
                menor = res;
                bolaMaisProxima = numero;
            }
            n--;
        }
        printf("%d\n", bolaMaisProxima);
     
    }
    return 0;
}
