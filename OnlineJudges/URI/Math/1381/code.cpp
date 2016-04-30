#include <bits/stdc++.h> 

using namespace std; 

#define EPS 1e-7
#define MOD 1300031

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

#define MAX MOD

ll mem[MAX];

int inv(int px) {
    	if (mem[px]) return mem[px];
    
    	int x = px;
	int y = MOD;
	int ax = 1, ay = 0, bx = 0, by = 1;
	
	//Perform extended gcd
	while(x) {
		if(x <= y) {
			int m = y / x;
			y -= m * x;
			ay -= ax * m;
			by -= bx * m;
		}
		else {
			swap(x, y);
			swap(ax, ay);
			swap(bx, by);
		}
	}

	int inverse = ay % MOD;
	if(inverse < 0) inverse += MOD;

    mem[px] = inverse;
    mem[inverse] = px;
    
    return inverse;
}
void solve(int x, int y) {
    ll result = 1;
    int m = min(y, x - y);
    for(int i = 1; i <= m; i++) {
        result *= (x-i+1);
	result *= inv(i);
	result = result % MOD;
    } 
    printf("%lld\n", result);
}

int main() {
    memset(mem, 0, sizeof mem);
    int t;
    scanf("%d", &t);
    while(t--) {
	int x, y;
    	scanf("%d %d", &x, &y);
    	solve(x+y-1, y);
    }
    
    return 0; 
}
