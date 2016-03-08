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

int n, m, pos;

int valueOf(char a, char b) {

    int x = min(a - 'a', b - 'a');
    int y = max(a - 'a', b - 'a');

    int result = min(y - x, 'z' - 'a' - y + x + 1);
    //printf("dist(%c,%c) = %d\n", a, b, result);
    return result;
}

int main() {
 
    while(scanf("%d %d",&n, &pos) != EOF){
        pos--;
        string str;
        cin >> str;

        int dist[n];
        memset(dist, 0, sizeof dist); 
        int ans = 0, l = 0, r = 0;
        for(int i = 0, j = n-1; i < j; i++, j--) {
            if(str[i] != str[j]) {
                dist[i] = dist[j] = valueOf(str[i], str[j]);
                ans += dist[i];
                int real_dist = abs(i-pos) < abs(j-pos) ? abs(i-pos) : abs(j-pos);
                int real_index = abs(i-pos) < abs(j-pos) ? i: j;
                if(real_index < pos) l = max(real_dist, l);
                else r = max(r, real_dist);
            }
        }
        //printf("%d %d\n", l, r);
        printf("%d\n", ans + l + r + (l && r)*min(l,r));
    }

    return 0; 
}
