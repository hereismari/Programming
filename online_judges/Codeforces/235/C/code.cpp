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

int n, m, x, y;

int main() {
 
    while(scanf("%d %d", &n, &m) != EOF) {

        if(m > 2*n + 2 || n > 1 + m) { puts("-1"); return 0; }

        while(m > n + 1 && n >= 1) { printf("110"); m -= 2; n -= 1; }
        
        if(n == 0 && m <= 2) for(int i = 0; i < m; i++) printf("1");
        
        else if(m > n) {
            
            for(int i = 0; n > 0; i++) {
                if(i % 2 == 0) { printf("1"); m -= 1; }
                else { printf("0"); n -= 1; }
            }
            
            if(m > 0) for(int i = 0; i < m; i++) printf("1");
        }
        else {
            for(int i = 0; m > 0; i++) {
                if(i % 2 == 1) { printf("1"); m -= 1; }
                else { printf("0"); n -= 1; }
            }

            if(n > 0) for(int i = 0; i < n; i++) printf("0");
        }
    }

	return 0; 
}
