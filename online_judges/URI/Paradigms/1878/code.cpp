#include <bits/stdc++.h> 
#define ll long long
 
using namespace std; 

ll n, m, x, y, a[3], calc[12][12][12];
bool poss;

void calculate() {

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 1; k <= m; k++)
                calc[i][j][k] = a[0] * i + a[1] * j + a[2] * k;
}


void verify() {

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 1; k <= m; k++)
                for(int l = 1; l <= m; l++)
                    for(int p = 1; p <= m; p++)
                        for(int q = 1; q <= m; q++)
                        {
                            if(i != l && j != p && k != q)
                                if(calc[i][j][k] == calc[l][p][q] && calc[i][j][k] != 0)
                                    poss = false;
                        }

}

int main() {
 
    while(scanf("%lld %lld", &n ,&m) != EOF) {
        
        a[0] = a[1] = a[2] = 0LL;
        poss = true;

        for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
        
        calculate();
        verify();
        
        if(poss) cout << "Lucky Denis!" << endl;
        else cout << "Try again later, Denis..." << endl;
    }

	return 0; 
}
