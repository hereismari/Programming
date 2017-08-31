#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE 1000

int tree[MAX_VALUE];
int tree2D[MAX_VALUE][MAX_VALUE];

/* returns information in [1, idx] */
int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

/* updates idx with value "val" */
void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

/* returns information in [1, idx][1, idy] */
int read2D(int idx, int idy){
    int sum = 0;
    while (idx > 0) {
        while (idy > 0) {
            sum += tree[idx][idy];
            idy -= (idy & -idy);
        }
        idx -= (idx & -idx);
    }
    return sum;
}

/* updates 2D segtree */
void update2D(int x , int y , int val){
    int y1;
    while (x <= max_x){
        y1 = y;
        while (y1 <= max_y){
            tree2D[x][y1] += val;
            y1 += (y1 & -y1); 
        }
        x += (x & -x); 
    }
}

/* get value of idx */
void readSingle(int idx) {

    int result = tree[idx];
    if(idx > 0) {
        int aux = (idx - (idx & -idx));
        idx--;
        while(idx != aux) { result -= tree[idx]; idx -= (idx & -idx); }
    }

    return result;
}

int main() {

	scanf("%d",&n);
	int maxVal = 0;
	for(int i = 0; i < n; i++) {scanf("%d",&a[i]); maxVal = max(a[i],maxVal);}
	


}
