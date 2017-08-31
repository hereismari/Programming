#include <bits/stdc++.h>
#define MAX 400

using namespace std;

int a[MAX][MAX];
int vis[MAX], L[MAX];
int n, m;

void buildMatrix() {
     memset(vis,-1,sizeof vis);
     for(int i = 0; i < n; i++)
         for(int j = 0; j < m; j++){
            scanf("%d",&a[i][j]);
         }
}

bool possible() {
    for(int i = 0 ; i < n-1; i++){
	for(int j = 0; j < m-1; j++)
	    if(a[i][j] % m != a[i+1][j] % m || (int)ceil(1.0 * a[i][j] / m) != (int) ceil(1.0* a[i][j+1] / m))
		 return false;
}
    return true;
}

int sorting(int l[], int size){
    int ans = 0;
    for(int i = 0; i < size; i++){
        int index_min = i;
        for(int j = i+1; j < size; j++)
            if(l[j] < l[index_min]) index_min = j;
        if(index_min != i) ans++;
    
        int tmp = l[i];
        l[i] = l[index_min];
        l[index_min] = tmp;
    }
    return ans;
}

int selection() {
    int ans = 0;
    for(int i = 0; i < m; i++) L[i] = a[0][i] % m == 0 ? m : a[0][i] % m;
    ans += sorting(L, m);
    for(int i = 0; i < n; i++) L[i] = (int)ceil(1.0 * a[i][0]/m);
    ans += sorting(L, n);
    return ans;
}

int main() {

    while(scanf("%d %d",&n,&m)!= EOF){
        buildMatrix();
        if(!possible()) printf("*\n");
        else printf("%d\n",selection());
    }
    return 0;
}
