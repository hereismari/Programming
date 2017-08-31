#include <bits/stdc++.h>

using namespace std;

int main() {

    int x, y;
    while(scanf("%d %d",&x,&y) != EOF) {
        printf("%d\n",int(ceil(y/((y-x)*1.0))));
    }
    return 0;
}
