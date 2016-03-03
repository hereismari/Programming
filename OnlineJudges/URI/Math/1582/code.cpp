#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b) { return b == 0 ? a : mdc(b, a % b); }

int main() {

    int a[3];
    while(scanf("%d %d %d",&a[0], &a[1], &a[2])) {
        sort(a, a+3);
        if(a[2] * a[2] == (a[1]*a[1] + a[0]*a[0]) && mdc(mdc(a[0],a[1]),a[2]) == 1)
            printf("tripla pitagorica primitiva\n");
        else if(a[2] * a[2] == (a[1]*a[1] + a[0]*a[0]))
            printf("tripla pitagorica\n");
        else
            printf("tripla\n");
    }

    return 0;
}
