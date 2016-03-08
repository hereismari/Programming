#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE 1100
#define HOMEM 0
#define ELEFANTE 1
#define RATO 2

int tree2D[3][MAX_VALUE][MAX_VALUE];
int n;

/* returns information in [1, idx][1, idy] */
int read(int idx, int idy) {
    int sum = 0;
    for(;idx > 0; idx -= (idx & -idx)) 
        for(int y1 = idy; y1 > 0; y1 -= (y1 & -y1))
            sum += tree2D[idx][y1]; 
    return sum;
}

int getIntervalSum(int x1, int y1, int x2, int y2) {
    return read(x2, y2) - read(x1-1, y2) - read(x2, y1-1) + read(x1-1, y1 -1);
}

/* updates 2D segtree */
void update(int idx , int idy , int val){
    int value = val - getIntervalSum(idx, idy, idx, idy);
    for(; idx < MAX_VALUE; idx += (idx & -idx))
        for(int y1 = idy; y1 < MAX_VALUE; y1 += (y1 & -y1))
            tree2D[idx][y1] += value;
}

int t, x, y, x2, y2, value;
char str[4];

int main() {

    while(scanf("%d %d", &n, &t) {

        memset(tree2D, 0, sizeof tree2D);
        
        while(t--) {
            scanf("\n%c", c);
            if(c == 'M') {
                scanf("%d %d", &x, &y);
                update(x, y);
            }
            else {
                scanf("%d %d", &x, &y);
                ll ans1 = getIntervaSum(1, 1, x, y
                printf("%d\n", getIntervalSum(x, y, x2, y2));
            }
        }
    }
}
