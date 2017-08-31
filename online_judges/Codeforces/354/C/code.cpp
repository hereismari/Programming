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
 
	scanf("%d %d", &n, &m);
    string s;

    cin >> s;
    
    int ans = 0;
    int aux[s.size() + 1];

    for(int i = 0; i < 2; i++) {
        queue<int> q;
        int local_max = 0, value = 0;
    
        aux[0] = 0;
        aux[1] = s[0] - 'a' == i;

        for(int j = 2; j <= s.size(); j++) {
            if(s[j-1] - 'a' == i && s[j-2] - 'a' == i) aux[j] = 1 + aux[j-1];
            else if(s[j-1] - 'a' != i && s[j-2] - 'a' == i) aux[j] = aux[j-1];
            else if(s[j-1] - 'a' != i) aux[j] = 0;
            else aux[j] = 1;
        }

        for(int j = 0; j < s.size(); j++) {
            if(s[j] - 'a' == i) value++;
            else {
                if(q.size() < m) { value++; q.push(j+1); }
                else if(m > 0) { value -= aux[q.front()]; q.pop(); q.push(j+1); }
                else value = 0;
            }

            local_max = max(local_max, value);
        }
        ans = max(ans, local_max);
    }

    printf("%d\n", ans);    
    return 0; 
}
