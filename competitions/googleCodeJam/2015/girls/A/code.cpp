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
    for(int counter = 1; counter <= n; counter++) {
        
        scanf("%d", &m);
        string s;
        cin >> s;
        
        string ans = "";
        for(int i = 0; i < 8*m; i+=8) {
            int aux = 0;
            for(int j = 0; j < 8; j++) {
               aux += (s[i+j] == 'I') * pow(2, 8-j-1); 
            }
            ans += char(aux);
       }
        
        printf("Case #%d: ", counter);
        cout << ans << endl;
    }
	return 0; 
}
