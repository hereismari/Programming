#include <bits/stdc++.h> 

#define MAX 100010 
#define EPS 1e-7

#define ll long long int

#define ULTRA_VALUE 150000 
using namespace std; 

int n, m, x, y;
int a[MAX], seg[5*MAX], higherLeft[MAX], higherRight[MAX];
stack<int> q;
bool print_space;

void buildLeft(int i) {
    while(!q.empty() && a[i] >= a[q.top()]) q.pop();
    higherLeft[i] = q.empty() ? i : q.top();
    q.push(i);
}

void buildRight(int i) {
    while(!q.empty() && a[i] >= a[q.top()]) q.pop(); 
    higherRight[i] = q.empty() ? i : q.top();
    q.push(i);
}

void buildSegTree(int b, int e, int id) {

    if(b == e) seg[id] = a[b];
    else {
        int m = (b+e)/2;
        buildSegTree(b, m, 2*id);
        buildSegTree(m+1, e, 2*id + 1);
        seg[id] = min(seg[2*id], seg[2*id + 1]);
    }
}

int query(int b, int e, int ini, int end, int id) {
    if(b > end || e < ini) return INT_MAX;
    if(b >= ini && e <= end) return seg[id];
    int m = (b+e)/2;
    return min(query(b, m, ini, end, id*2), query(m+1, e, ini, end, id*2 + 1));
}

int getLeft(int i) {

    int maxLeft = higherLeft[i];
    if(maxLeft == i) return a[i];

    int end = i-1;
    int ini = maxLeft+1;
    return a[i] - query(1, n, ini, end, 1);
}

int getRight(int i) {

    int maxRight = higherRight[i];
    if(maxRight == i) return a[i];

    int ini = i+1;
    int end = maxRight-1;
    return a[i] - query(1, n, ini, end, 1);
}

bool isUltra(int i) {

    int minorLeft = getLeft(i);
    int minorRight = getRight(i);
    if(minorLeft >= ULTRA_VALUE && minorRight >= ULTRA_VALUE) {
        if(print_space) printf(" ");
        printf("%d", i);
        print_space = true;
    }
}

int main() {

    memset(a, INT_MAX, sizeof a);
    while(scanf("%d", &n) != EOF) {

        memset(higherLeft, -1, sizeof higherLeft);
        memset(higherRight, -1, sizeof higherRight);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        
        while(!q.empty()) q.pop();
        for(int i = 1; i <= n; i++) buildLeft(i);
        while(!q.empty()) q.pop();
        for(int i = n; i >= 1; i--) buildRight(i);

        buildSegTree(1, n, 1);
        print_space = false;
        for(int i = 1; i <= n; i++) if(a[i] > a[i-1] && a[i] > a[i+1]) isUltra(i);
        printf("\n");    
    }

	return 0; 
}

