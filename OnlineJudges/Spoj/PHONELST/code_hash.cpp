#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MAX 10200
#define MOD 1000000007
#define BASE 257

int n;
string aux;
bool ans;

int trie[MAX][30];
bool isleaf[MAX][30];

int cur;

void add_in_trie(int pos, string s, int i) {
    
    if(i >= s.size()) return;

    int nxt = s[i] - '0';
    if(!trie[pos][nxt]) 
        trie[pos][nxt] = ++cur; 
    
    if(i == s.size() - 1) isleaf[pos][nxt] = true;
    add_in_trie(trie[pos][nxt], s, i+1);
}

void dfs(int pos = 0, bool flag = false) {
    
    bool flag2 = false;
    for(int i = 0; i < 30; i++) {
        if(trie[pos][i]) {
            dfs(trie[pos][i], isleaf[pos][i]);
            flag2 = true;
        }
    }

    if (flag && flag2) ans = false;
}

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {

        cur = 0;
        ans = true;
        
        for(int i = 0; i < MAX; i++) {
            for(int j = 0; j < 30; j++) {
                trie[i][j] = 0; isleaf[i][j] = false;
            }
        }

        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            cin >> aux;
            add_in_trie(0, aux, 0);
        }
        
        dfs();

        printf("%s\n", ans ? "YES" : "NO");
    }

    return 0;
}
