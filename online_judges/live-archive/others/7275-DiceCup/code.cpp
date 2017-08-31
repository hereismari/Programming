#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    bool flag = false;
    while(scanf("%d %d", &n, &m) != EOF) {
        
        if(flag) puts("");
        flag = true;

        int a[50];
        memset(a, 0, sizeof a);

        int mx = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) { 
                a[i+j]++;
                mx = max(mx, a[i+j]);  
            }

        set<int> s;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(a[i+j] == mx)
                    s.insert(i+j);
        for(set<int>::iterator it = s.begin(); it != s.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}
