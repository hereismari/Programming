#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    int x, y;

    scanf("%d %d", &n, &m);

    int ones = 0, minus_ones = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 1) ones++;
        else minus_ones++;
    }

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        int aux = y - x + 1;
        printf("%c\n", !(aux % 2) && aux <= min(ones, minus_ones) * 2 ? '1' : '0');
    }

    return 0;
}
