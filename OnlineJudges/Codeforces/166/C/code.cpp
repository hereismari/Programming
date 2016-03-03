#include <bits/stdc++.h>
#define MAX 3000005

using namespace std;

int tree[MAX][26];
char a[MAX];
int n,k;
int cur = 0, ans = -1;
int bad[100];

void ins(int x, int i){
    if(i == n) return ;
    int nxt =  a[i]-'a';
    if(!tree[x][nxt]) 
        tree[x][nxt] = ++cur;
    ins(tree[x][nxt],i+1);
}
void calc(int x, int danger){
    if(danger > k) return ;
    ++ans;
    for(int i = 0; i < 26;++i)
        if(tree[x][i]) calc(tree[x][i], danger + bad[i]);
}

int main(){

	char aux[100];
    scanf("%s %s",a,aux); 
    for(int i = 0; i < 26; i++)
		bad[i] = (aux[i] == '0');

    scanf("%d",&k);
    n = strlen(a);   
	for(int i = 0; i < n; i++)
        ins(0,i);
    
	calc(0,0);
    cout << ans << endl;
	return 0;
}
