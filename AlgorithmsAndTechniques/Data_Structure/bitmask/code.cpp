#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7
#define MOD 1000000007

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

int solve(int quant_bits) {
    
    int result = INT_MAX;

    for(int mask = 0; mask != (1 << quant_bits); mask++) {
            
        bitset<8> bs(mask);
        int num = 0;
        int cont = 0;

        for(int i = 0; i < quant_bits; i++) {
            if(bs.test(i)) {
                num = num * 10 + 4;
                cont += 4;
            }
            else {
                num = num * 10 + 7;
                cont += 7;
            }
        }
        
        if(cont == n)
            result = min(result, num);
    }

    return result;
}

int main() {
 
    while(scanf("%d", &n) != EOF){
        
        int ans = INT_MAX;
        for(int i = 1; i <= 7; i++)
            ans = min(ans, solve(i));

        if(ans == INT_MAX) printf("-1\n");
        else printf("%d\n", ans);
    }

	return 0; 
}
