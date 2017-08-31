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

    scanf("%d", &n);
    while(n--){

        scanf("%d %d", &x, &y);

        printf("%d\n", int(ceil((x-2.0)/3)*ceil((y-2.0)/3)));

    }

	return 0; 
}
