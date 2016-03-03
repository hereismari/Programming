#include <bits/stdc++.h>

#define MAX 300010
#define ll long long int

using namespace std;

int n, m, q;
int pre[MAX], pos[MAX];
char c, s[MAX];

int main() {
	
    scanf("%d %d",&n, &q);
	scanf("\n%s", s);
    
    for(int i = 0; i < n; i++) {
        if(i > 0 && s[i] == '.' && s[i-1] == '.')
            pre[i] = pre[i-1];
        else if(s[i] == '.')
            pre[i] = i;
    }

    for(int i = n-1; i >= 0; i--) {
        if(i < n-1 && s[i] == '.' && s[i+1] == '.')
            pos[i] = pos[i+1];
        else if(s[i] == '.')
            pos[i] = i;
    }

    int ans = 0;
    for(int i = 0; i < n;) {
        if(s[i] == '.') { 
            ans += (pos[i] - pre[i]);
            i += (pos[i] - pre[i] + 1);
        }
        else i++;
    }

    for(int i = 1 ; i <= q ; i++){
		
        scanf("%d %c", &m, &c);
        m--;
        
        if(s[m] != '.' && c != '.') printf("%d\n", ans);
        else if (s[m] == c) printf("%d\n", ans);
        
        else if(c != '.' && s[m] == '.') {
            s[m] = c;
            if(m > 0 && s[m-1] == '.') ans--;
            if(m < n-1 && s[m+1] == '.') ans--;
            printf("%d\n", ans);
        }
        
        else if(c == '.' && s[m] != '.') {
            s[m] = '.';
            if(m > 0 && s[m-1] == '.') ans++;
            if(m < n-1 && s[m+1] == '.') ans++;
            printf("%d\n", ans);
        }
    }

	return 0;
}
