#include <bits/stdc++.h>
#define MAX 20
#define ll long long int
using namespace std;

int n, m;
ll B[MAX];

bool fold(ll A[], int size) {

    if(size < m)  return false;
    if(size == m) {

        bool ans = true;
        for(int i = 0; i < size; i++) ans = A[i] == B[i];
        if (ans) return true;
       
		ans = true;
        for (int i = 0; i < size; i++) ans = A[i] == B[size - i - 1];
        if (ans) return true;
     
		return false;
    }

    ll C[MAX], new_size;
    for (int i = 1; i < size; i++) {
        new_size = size - min(i, size - i);
        int l, r;
        for(l = i - 1, r = i; l >= 0 && r < size; l--, r++)
            C[--new_size] = A[l] + A[r];

        while (l >= 0)  C[--new_size] = A[l--];
        while (r < size)   C[--new_size] = A[r++];
        new_size = size - min(i, size - i);
	    if (fold(C, new_size)) return true;
    }
    
    return false;
}

int main() {

	ll A[MAX];
	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < n; i++) scanf("%lld",&A[i]);
		scanf("%d",&m);
	    for(int i = 0; i < m; i++) scanf("%lld",&B[i]);
		if(fold(A,n)) printf("S\n");
		else printf("N\n");
	}
}
