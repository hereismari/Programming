#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, p, k;
    while (scanf("%d %d %d", &n, &p, &k) != EOF) {
        vector < int > barra;
        for (int i = max(1, p-k); i <= min(n, p+k); i++)
            barra.push_back(i);

        if (barra[0] != 1) printf("<< ");
        for (int i = 0; i < barra.size(); i++) {
            if (i > 0) printf(" ");
            if (barra[i] == p) printf("(");
            printf("%d", barra[i]);
            if (barra[i] == p) printf(")");
        }
        if (barra[barra.size()-1] != n) printf(" >>");
        printf("\n");
    }
    return 0;
}
