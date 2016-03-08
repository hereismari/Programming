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
 
    scanf("%d", &n);
    int a[n];
    bool valid[n];
    for(int i = 0; i <n; i++) scanf("%d", &a[i]);
    memset(valid, true, sizeof valid);
    int flag = false;
    int ans = -1, cont = 0;
    int dir = 0;
    while(!flag) {
        flag = true;
        if (dir % 2 == 0) {
            for(int i = 0; i < n; i++){
                if(a[i] <= cont) {cont += valid[i]; valid[i] = false;}
                else flag = false;
            }
        }
        else{
            for(int i = n-1; i >= 0; i--){
                if(a[i] <= cont) { cont += valid[i]; valid[i] = false;}
                else flag = false;
            }
        }
        dir += 1;
        ans++;
    }

    printf("%d\n", ans);
	return 0; 
}
