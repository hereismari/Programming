#include <bits/stdc++.h>
#define MAX 10010

using namespace std;

int a[MAX];
int main(){

	int n,k,x;
	int cont = 1;
	while(1){
		scanf("%d %d",&n,&k);
		if(n == 0 && k == 0) break;
		for(int i = 0 ; i < n; i++) scanf("%d",&a[i]);
		sort(a,a+n);

        map<int,int> m;
        for(int i = 0; i < n ; i++)
            if(m.find(a[i]) == m.end())
                m[a[i]] = i+1;

		printf("CASE# %d:\n",cont++);
		for(int i = 0 ; i < k; i++) {
			scanf("%d",&x); 
		    if(m.find(x) != m.end())
			    printf("%d found at %d\n",x,m[x]);
			else printf("%d not found\n",x);
		}
	}
	return 0;
}
