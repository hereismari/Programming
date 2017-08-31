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
bool valid(int k) {

    bool a[10];
    memset(a, false, sizeof a);

    while(k > 0) {
        int i = k % 10;
        if(a[i]) return false;
        a[i] = true;
        k /= 10;
    }

    return true;

}
int main() {
 
    while(scanf("%d %d",&n, &m) != EOF){
        int ans = 0;

        for(int i = n; i <= m; i++)
            if(valid(i)) ans++;
        
        printf("%d\n", ans);
    }

	return 0; 
}
