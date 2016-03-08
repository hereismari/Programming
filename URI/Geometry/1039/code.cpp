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

ll ra, xa, ya, rb, xb, yb;
int main() {
 
    while(scanf("%lld %lld %lld %lld %lld %lld", &ra, &xa, &ya, &rb, &xb, &yb) != EOF) {
        double dist = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
        if(dist  + rb <= ra)
            printf("RICO\n");
        else
            printf("MORTO\n");
    }

	return 0; 
}
