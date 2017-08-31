#include<bits/stdc++.h>
#define MAX 701000

using namespace std;

int n, m, a[MAX];

int main() {

    while(scanf("%d %d", &n, &m) != EOF) {

        for (int i = 0; i < m; i++)
           scanf("%d", &a[i]);

        a[m] = a[0] + n;
        bool can = false;
        int size = n/m;

        for(int i = a[0]; i < a[1]; i++) {
            bool flag = true;
            int aux = i;
            for (int j = 1; j <= m; j++) {
                if(aux < a[j] && a[j] >= aux + size) aux += size;
                else { flag = false; break; }
            }
            if(flag) { can = true; break;}
        }

        puts(can ? "S" : "N");
    }
    return 0;
}
