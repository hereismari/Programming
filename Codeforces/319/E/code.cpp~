#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define MAX 1300000
#define pii pair<int,int>
#define DIVISOR 1000

using namespace std;

int n;
map<pii,int> id;
pii a[MAX];

bool comp(pii a, pii b) {
	if (a.F / DIVISOR != b.F / DIVISOR) return a.F/DIVISOR < b.F/DIVISOR;
	return (a.F / DIVISOR) % 2 == 0 ? a.S < b.S : a.S > b.S;
}

int main() {

    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d %d",&a[i].F, &a[i].S), id[a[i]] = i;
    
    sort(a, a + n , comp);
    
    for(int i = 0; i < n; i++) printf("%d ",id[a[i]] + 1);
    printf("\n");

    return 0;
}
