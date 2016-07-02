#include <bits/stdc++.h> 

using namespace std; 

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

#define MAX 1000100  
#define INF 1000000000

int n, m, x, y;

int main() {
 
    string s;
    cin >> s;

    int n = s.size();
    int cont[30], cont2[30];

    memset(cont, 0, sizeof cont);
    memset(cont2, 0, sizeof cont2);

    for(int i = 0; i < n; i++)
        cont[s[i] - 'a']++;
    
    int change = -1; 
    for(int i = 0, j = 29; i < 30; i++) { 
    
        if(cont[i] & 1) {
            while(!(cont[j] & 1)) j--;
            if(i < j) {
                cont2[i] = cont[i] + 1;
                cont2[j] = cont[j] - 1;
                j--;
            }
            else if(change == -1) { cont2[i] = cont[i]; change = i; }
        }
        else cont2[i] = cont[i];
    }

    string ans = s;
    for(int i = 0, j = 0; i < 30 && j < n/2; i++) {
        for(int k = 0; k < cont2[i]/2; k++)
            ans[j++] = char('a' + i);
    }

    if(n & 1) {
        ans[n/2] = char('a' + change);
        for(int i = n/2 + 1, k = 2; i < n; i++, k++)
            ans[i] = ans[n/2 + 1 - k];
    }
    else {
        for(int i = n/2, k = 1; i < n; i++, k++) {
            ans[i] = ans[n/2 - k];
        }
    }

    cout << ans << endl;
	return 0; 
}
