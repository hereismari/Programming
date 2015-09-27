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

ll n, m, x, y;

int main() {
 
    while(scanf("%lld %lld",&n, &m) != EOF){
        printf("%lld\n", n ^ m);
    }

	return 0; 
}
