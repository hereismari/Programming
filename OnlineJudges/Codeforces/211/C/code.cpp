#include <bits/stdc++.h> 

#define MAX 200100 
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

int n, m, ans[MAX];
char str[MAX];

int main() {
 
    scanf("\n%s", str);
    n = strlen(str);

    memset(ans, 0, sizeof ans);
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) ans[j] = 1;
        else if(str[i] == str[i-1]) ans[j]++;
        else { j++; ans[j]++;}
    }

    bool flag = true;
    for(int i = 0, k = 0; i < n; k++) {
        if(ans[k] == 1) { printf("%c", str[i]); flag = true; i++; }
        else {
            printf("%c", str[i]);
            if(flag) printf("%c", str[i]);
            while(ans[k]-- > 0) i++;
            flag = !flag;
        }
    }

    puts("");
	return 0; 
}
