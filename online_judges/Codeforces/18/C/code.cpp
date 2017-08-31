#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y, ans;

void checkLeft(int a[]) {

    int acum[n];
    acum[0] = a[0];
    for(int i = 1; i < n; i++) acum[i] = a[i] + acum[i-1];

    for(int i = 0; i < n-1; i++) {
        if(acum[i] == acum[n-1] - acum[i])
            ans++;
    }
}

void checkRight(int a[]) {

    int acum[n];
    acum[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) acum[i] = a[i] + acum[i+1];

    for(int i = n-1; i > 0; i--)
        if(acum[i] == acum[0] - acum[i])
            ans++;
}

int main() {
 
    while(scanf("%d",&n) != EOF){

        ans = 0;
        int a[n];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        checkLeft(a);
        checkRight(a);

        printf("%d\n", ans / 2);
    }

	return 0; 
}
