#include <bits/stdc++.h>

using namespace std;

int main() {

    int n = 5;
    int a[n],b[n];
    while(scanf("%d",&a[0]) != EOF) {
        bool flag = true;
        for(int i = 1; i < n; i++) scanf("%d",&a[i]);
        for(int i = 0; i < n; i++) scanf("%d",&b[i]);
        for(int i = 0; i < n; i++)
            if(a[i] == b[i]) flag = false;

        printf("%c\n",flag ? 'Y' : 'N');
    }
    return 0;
}
