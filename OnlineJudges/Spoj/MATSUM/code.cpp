#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE 1100

int tree2D[MAX_VALUE][MAX_VALUE];
int n;

/* returns information in [1, idx][1, idy] */
int read(int idx, int idy){
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

	scanf("%d",&t);
    while(t--) {

        memset(tree2D, 0, sizeof tree2D);
        scanf("%d", &n);
        
        while(true) {
            scanf("\n%s", str);
            if(str[1] == 'N') break;
            else if(str[1] == 'E') {
                scanf("%d %d %d", &x, &y, &value);
                x++; y++;
                update(x, y, value);
            }
            else {
                scanf("%d %d %d %d", &x, &y, &x2, &y2);
                x++; y++; x2++; y2++;
                printf("%d\n", getIntervalSum(x, y, x2, y2));
            }
        }
    }
}
