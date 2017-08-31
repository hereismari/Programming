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
 
    while(scanf("%d",&n) != EOF){

        int a[n+1] , b[n+1], pos[n+1], aux[n+1];
        for(int i = 1; i <= n; i++) { scanf("%d", &a[i]);}
        for(int i = 1; i <= n; i++) { scanf("%d", &b[i]); pos[b[i]] = i; }

	int ans1 = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(a[j] == b[i]) { aux[i] = j; ans1 += abs(i-j); break;}


       vector<pii> ans;
       for(int i = 1; i <= n; i++) {
            for(int j = aux[i] - 1; j >= i; j--) 
                    if(pos[a[j]] >= aux[i]) {
                        ans.pb(mp(aux[i], j));
                        swap(a[aux[i]], a[j]);
			            aux[i] = j;
                    }
       }

       printf("%d\n%d\n", ans1 / 2, ans.size());
       for(int i = 0; i < ans.size(); i++)
           printf("%d %d\n", ans[i].F, ans[i].S);
    }

	return 0; 
}
