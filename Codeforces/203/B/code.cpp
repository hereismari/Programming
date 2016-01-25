#include <bits/stdc++.h> 

#define MAX 100010 
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

int n;
int type[MAX], from[MAX], valid[MAX];

int calculate(int i) {
    if (i == 0 || valid[i] > 1 || type[i] == 1) return 0;
    else return calculate(from[i]) + 1;
}

int main() {
 
    while(scanf("%d",&n) != EOF){

        memset(valid, sizeof valid, 0);
        memset(from, sizeof from, 0);
        memset(type, sizeof type, 0);

        for(int i = 1; i <= n; i++) 
            scanf("%d", &type[i]);
        
        for(int i = 1; i <= n; i++) {
            scanf("%d", &from[i]);
            valid[from[i]]++;
        }
        
        int ans = 0, index = 0, aux;
        for(int i = 1; i <= n; i++) {
            if(type[i] == 1 && (aux = calculate(from[i]) + 1) > ans) {
                ans = aux;
                index = i; 
            }
        }

        vector<int> final_ans;
        printf("%d\n", ans);
        for(int i = 0; i < ans; i++) { 
            final_ans.pb(index);
            index = from[index];
        }
        
        for(int i = ans - 1; i >= 0; i--) printf("%d ", final_ans[i]);

    }

	return 0; 
}
