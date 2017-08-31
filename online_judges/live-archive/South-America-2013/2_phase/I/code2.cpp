#include <bits/stdc++.h> 

#define MAX 101 
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
 
    while(scanf("%d",&n) != EOF) {
        
        int freq[MAX], maxValue = -1;
        memset(freq, 0, sizeof freq);
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            freq[x]++;
            if(x > maxValue) maxValue = x;
        }
        
        vector<ll> tree;
       
        ll aux = 1;
        for(int i = maxValue; i > 0; i--) {
            for(int j = 0; j < freq[i]; j++)
                tree.pb(aux);
            
            vector<ll> new_tree;
            for(int j = 0; j < tree.size(); j+=2) {
                ll newValue = tree[j] + tree[j+1];
                ll maxAux = max(tree[j], tree[j+1]);
                new_tree.pb(newValue);
                if(maxAux > aux) aux = maxAux;
            }
            tree = new_tree;
        }

        printf("%lld\n", tree[0]);
    }

	return 0; 
}
