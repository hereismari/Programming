#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;

int main() {
 
    while(scanf("%d %d",&n, &m) != EOF) {
        int a[n]; for(int i = 0; i < n; i++) a[i] = 0;
        for(int i = 0 ; i < n*m; i++)
        {
            scanf("%d", &x);
            a[i % n] += x;
        }

        int ans = 0, index = -1;
        for(int i = 0; i < n; i++){
            if(a[i] >= ans) { index = i; ans = a[i]; }
        }

       printf("%d\n", index + 1);
    }

	return 0; 
}
