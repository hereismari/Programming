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
 
    int b, c1, c2, c3;

    while(scanf("%d %d %d %d",&b, &c1, &c2, &c3) != EOF){
        if(b == 0 && c1 == 0 && c2 == 0 && c3 == 0) break;
        int ans = 720 + 360;
        ans += (b - c1) > 0 ? (b - c1) * 9 : (b - c1 + 40) * 9;
        ans += (c2 - c1) > 0 ? (c2 - c1) * 9 : (c2 - c1 + 40) * 9; 
        ans += (c2 - c3) > 0 ? (c2 - c3) * 9 : (c2 - c3 + 40) * 9; 
        printf("%d\n", ans);
    }

	return 0; 
}
