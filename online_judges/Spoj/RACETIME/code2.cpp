#include <bits/stdc++.h>

using namespace std;

int main() {

    int a[] = {10, 9, 1, 0, -1, -2, -3};

    sort(a, a + 3);
    sort(a+3, a + 7);
    for(int i = 0; i < 7; i++)
        printf("%d ", a[i]);
    puts("");

    return 0;
}

