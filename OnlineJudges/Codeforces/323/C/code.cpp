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

int n, x, y;
vector<int> a;
map<int,int> m;

int main() {
 
    scanf("%d", &n);
    for(int i = 0; i < n*n; i++) {
        scanf("%d", &x);
        a.pb(x);
    }

    sort(a.begin(), a.end());
    vector<int> ans;

    for(int i = a.size()-1; i >= 0; i--){
        int value = a[i];
        if(m[value] < 0) { m[value]++; continue; }
        else{
            for(int i = 0; i < ans.size(); i++)
               m[__gcd(value, ans[i])] -= 2;
            ans.pb(value);
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
    }


	return 0; 
}
