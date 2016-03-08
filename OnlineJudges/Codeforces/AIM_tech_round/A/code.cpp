#include <bits/stdc++.h>

int main() {

    double l, d, v1, v2;

    scanf("%lf %lf %lf %lf", &d, &l, &v1, &v2);

    double v = (l-d) / (v1 + v2);
    printf("%.20lf\n", v);
    return 0;
}
