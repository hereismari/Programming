#include <bits/stdc++.h>

using namespace std;

int main() {
    
    queue<int> q;
    int n, t, l, x;
    scanf("%d %d %d", &n, &t, &l);
    for(int i = 0; i < n-1; i++) {
        scanf("%d", &x);
        q.push(x);
    }

    int a[2];
    a[0] = a[1] = 0;
    int i = 0;
    while(!q.empty()) {
        int s = q.front(); q.pop();
//        printf("%d\n",t);
        if(abs(t-s) <= l) { a[i%2] += abs(t-s); t = s;}
        i++;
    }

    printf("%d %d\n",a[0],a[1]);
    return 0;
}
