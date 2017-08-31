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


int main() {
 
    int d, vf, vg;
    while(scanf("%d %d %d",&d, &vf, &vg) != EOF){
        printf("%c\n", 12.0*vg >= sqrt(144 + d*d)*vf ? 'S' : 'N'); 
        
    }

	return 0; 
}
