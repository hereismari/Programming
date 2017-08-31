#include <bits/stdc++.h>
#define MAX 1000005

using namespace std;

bool esp[MAX][26];
int tree[MAX][26];

char a[MAX];
int n,m;
int cur = 0, ans = 0;

void ins(int x, int i){
    if(i == n) return ;
    int nxt =  a[i]-'a';
    if(!tree[x][nxt]) 
        tree[x][nxt] = ++cur;

    if(i == n-1) esp[x][nxt] = true;
    ins(tree[x][nxt],i+1);
}

//DFS
void calc(int x, int value, bool special) {
    
    int neigh = 0;
    for(int i = 0; i < 26; i++) if(tree[x][i]) neigh++;
    if(special) ans += value; 
    if(neigh > 1 || special || x == 0) value++;
    for(int i = 0; i < 26; i++)
        if(tree[x][i]) calc(tree[x][i], value, esp[x][i]);
}

int main(){


    while(scanf("%d", &m) != EOF) {
        memset(esp, false ,sizeof esp);
        memset(tree, 0, sizeof tree);
        ans = 0;
        for(int i = 0 ; i < m; i++) {
            scanf("%s",a); 
            n = strlen(a);   
            ins(0,0);
        }
	    calc(0,0, false);
	    printf("%.2f\n", ans/(1.0*m));
    }
    return 0;
}
