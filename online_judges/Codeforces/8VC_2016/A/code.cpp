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

int n;

int main() {
 
    while(scanf("%d",&n) != EOF){

        string str;
        cin >> str;

        int ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int x = 0, y = 0;           
                for(int k = j; k <= i; k++) {
                    if(str[k] == 'U') y += 1;
                    else if(str[k] == 'R') x += 1;
                    else if(str[k] == 'D') y -= 1;
                    else if(str[k] == 'L') x -= 1;
                }
                if(x == 0 && y == 0) ans++;
            }
        }
        printf("%d\n", ans);
    }

	return 0; 
}
