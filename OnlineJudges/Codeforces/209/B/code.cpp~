#include <bits/stdc++.h>

#define MAX 100010

using namespace std;

int n, k;
int a[MAX];

int main() {

     cin >> n >> k;

     for(int i = 1; i <= 2*n; i ++) a[i] = i;
     for(int i = 1, q = 1; i <= k; i ++, q += 2) swap(a[q], a[q+1]);
     
     for(int i = 1; i <= 2*n; i ++) printf("%d ", a[i]);
	 printf("\n");     
}
