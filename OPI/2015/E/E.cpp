#include <cstdio>
using namespace std;

#define range(i, n) for(int i=0; i<n; i++)
int normal[12] =   {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int bissexto[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int a1, m1, d1;
int a2, m2, d2;

bool is_bissexto(int x) {
    return x%400==0 or x%4==0 and x%100!=0;
}

void mswap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_all() {
    mswap(&a1, &a2);
    mswap(&m1, &m2);
    mswap(&d1, &d2);
}

int run() {
    if(d1 > d2) swap_all();
    if(m1 > m2) swap_all();
    if(a1 > a2) swap_all();

    int answer = d2-d1;

    for(int i=m1; i<=12; i++) answer += is_bissexto(a1)? bissexto[i-1] : normal[i-1];
    for(int i=m2; i<=12; i++) answer -= is_bissexto(a2)? bissexto[i-1] : normal[i-1];

    for(int i=a1+1; i<=a2; i++) answer += is_bissexto(i)? 366 : 365;

    printf("%d\n", answer);
}

int main()
{
    while(scanf("%d:%d:%d\n%d:%d:%d", &a1, &m1, &d1, &a2, &m2, &d2) != EOF)
        run();
    return 0;
}
