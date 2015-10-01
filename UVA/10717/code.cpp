#include <bits/stdc++.h> 

#define MAX 12
#define MAX2 60
#define EPS 1e-7

#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

using namespace std; 

int n, m, x, y;
int ans1[MAX], ans2[MAX];
int c[MAX2], table[MAX];

int lcm(int a, int b) {
    return a /__gcd(a, b) * b;
}

int main() {
 
    while(scanf("%d %d",&n, &m) && (n || m)){

        for(int i = 0; i < n; i++) scanf("%d", &c[i]);
        for(int i = 0; i < m; i++) scanf("%d", &table[i]);

        memset(ans1, -1, sizeof ans1);
        memset(ans2, -1, sizeof ans2);

        for(int i1 = 0; i1 < n; i1++)
            for(int i2 = i1+1; i2 < n; i2++)
                for(int i3 = i2+1; i3 < n; i3++)
                    for(int i4 = i3+1; i4 < n; i4++){
                        int x = lcm(c[i1], lcm(c[i2], lcm(c[i3], c[i4])));
                        for(int i = 0; i < m; i++){
                            int lower = table[i]/x * x;
                            int upper = (table[i] + x - 1)/x * x;

                            if(ans1[i] < 0 || ans1[i] < lower)
                                ans1[i] = lower;
                            if(ans2[i] < 0 || ans2[i] > upper)
                                ans2[i] = upper;
                        }
                    }

        for(int i = 0; i < m; i++)
            printf("%d %d\n", ans1[i], ans2[i]);

    }

	return 0; 
}
