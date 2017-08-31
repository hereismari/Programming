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

int main() {
 
    while(scanf("%d",&n) != EOF) {

        int r[n], l = 0, p = 0;
        int a, b, c;
        for(int i = 0; i < n; i++) {
            scanf("%d^%d", &a, &b);
            scanf("%d!", &c);
               
            double log1 = log10(a) * b;
            double log2 = 0;
            for(int k = 1; k <= c; k++) log2 += log10(k);

            if(log1 >= log2) { r[i] = 1; l++; }
            else { r[i] = 2; p++; }
        }

        if(l > p) printf("Campeao: Lucas!\n");
        else if(p > l) printf("Campeao: Pedro!\n");
        else printf("A competicao terminou empatada!\n");
        for(int i = 0; i < n; i++) {
            if(r[i] == 1) printf("Rodada #%d: Lucas foi o vencedor\n", i+1);
            else printf("Rodada #%d: Pedro foi o vencedor\n", i+1);
        }
    }

	return 0; 
}
