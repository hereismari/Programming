#include <bits/stdc++.h> 

#define MAX 1000100 
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
vpii v;

int main() {
 
    while(scanf("%d",&n) != EOF){
        
        v.clear();
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            v.pb(mp(x,y));
        }
    
        sort(v.begin(), v.end());

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int max_value = INT_MIN;
            int min_value = INT_MAX;
            for(int j = i+1; j < n; j++){
                if(v[j].S > v[i].S){
                    if(v[j].S < min_value){
                        ans++;
                        min_value = v[j].S;
                    }
                }
                 else if(v[j].S > max_value){
                    ans++;
                    max_value = v[j].S;
                 }
            }
        }
        printf("%d\n", ans);
    }
	return 0; 
}
