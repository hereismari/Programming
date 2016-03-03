#include <stdio.h>
#include <string.h>

#define MAX 2000
using namespace std;

int maior_index, m[MAX], n, x, v;

int main() {

    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&v);
        memset(m,0,sizeof m);
        for(int i = 0; i < v; i++){
            scanf("%d",&x);
            m[x]++;
        }
        maior_index = 1;
        for(int i = 1; i <= 1000; i++)
            if(m[i] > m[maior_index]) maior_index = i;

        printf("%d\n",maior_index);

    }
    return 0;
}
