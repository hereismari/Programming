#include <bits/stdc++.h>
 
#define LEFT(i) (i << 1)
#define RIGHT(i) ((i << 1) + 1)
#define MID(left, right) ((left + right) >> 1)
 
#define MAX 600010
#define ll long long int
 
using namespace std;

struct node { 
    
	int h, e, r; 
    int lazy;

    node() {}
    node(int h) : h(h), e(0), r(0), lazy(0) {}
    node(int h, int e, int r) : h(h), e(e), r(r), lazy(0) {}

    node rotate(int n) {
        n %= 3;
        lazy += n;
        if (n == 1) {
            swap(h, e); swap(h, r);
        } else if (n==2) { 
            swap(e, r); swap(h, r); 
        }
        return *this;
    }
    
    node operator + (node x) {
        return node(h + x.h, e + x.e, r + x.r);    
    }
};

struct Segtree {

    node T[MAX];
    int n;

    Segtree() {}
    
    void clear(int n) {
		
		//n will be a pow(2, k), k is an int.
        while(n != n&-n) n += n&-n;
        this->n = n;               
        
        build(1, 1, n);
    }
    
    void build(int id, int a, int b) {
        T[id] = node(b-a+1);
        
        if(a>=b) return;
        build(LEFT(id), a, (a+b)/2);
        build(RIGHT(id), (a+b)/2+1, b);
    }
    
    node update(int id, int a, int b, int i, int j, int carry, int inc) {
        
		    T[id].rotate(carry);

        if (i > b || j < a) return node(0);
        if (i <= a && b <= j) return T[id].rotate(inc);
        
        node answer = 
            update(LEFT(id), a, (a+b)/2, i, j, T[id].lazy, inc) + 
            update(RIGHT(id), (a+b)/2+1, b, i, j, T[id].lazy, inc);
        
        T[id] = T[LEFT(id)] + T[RIGHT(id)];
        
        return answer;
    }

    node update(int i, int j, int inc) {
        return update(1, 1, n, i, j, 0, inc);
    }

    node query(int i, int j) {
        return update(1, 1, n, i, j, 0, 0);
    }

};

Segtree T;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
        T.clear(n);
        for(int i=0; i<m; i++) {
            char cmd; int a, b;
            scanf("\n%c %d %d", &cmd, &a, &b);
            if (cmd == 'M') {
                T.update(a, b, 1);
            } else {
                node q = T.query(a, b);            
                printf("%d %d %d\n", q.h, q.e, q.r);
            } 
        }
        printf("\n");
    }
}
