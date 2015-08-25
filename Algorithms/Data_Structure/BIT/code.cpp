#include <bits/stdc++.h>

using namespace std;

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void update(int x , int y , int val){
    int y1;
    while (x <= max_x){
        y1 = y;
        while (y1 <= max_y){
            tree[x][y1] += val;
            y1 += (y1 & -y1); 
        }
        x += (x & -x); 
    }
}

int main() {

	scanf("%d",&n);
	int maxVal = 0;
	for(int i = 0; i < n; i++) {scanf("%d",&a[i]); maxVal = max(a[i],maxVal);}
	


}
