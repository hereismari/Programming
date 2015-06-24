#include <bits/stdc++.h>

using namespace std;
 
struct volunteer {
    char choice1[10];
    char choice2[10];
} v[30 + 5];
 
int shirt_avail[6 + 3];
int n, m;
bool possible;
 
void reset(int p)
{
    for (int i = 0; i < 9; i++)
        shirt_avail[i] = p;
}
 
int shirt_index(char *k)
{
    if ( strcmp (k, "XXL") == 0 ) return 0;
    if ( strcmp (k, "XL") == 0 ) return 1;
    if ( strcmp (k, "L") == 0 ) return 2;
    if ( strcmp (k, "M") == 0 ) return 3;
    if ( strcmp (k, "S") == 0 ) return 4;
    return 5;
}
 
void bktk (int p)
{
    if (p == m) { possible = true; return; }
    if (possible == true) return;
 
    if (shirt_avail[shirt_index(v [p].choice1)]) {
        shirt_avail[shirt_index(v [p].choice1)]--;
        bktk(p + 1);
        shirt_avail[shirt_index(v [p].choice1)]++;
    }
    if (shirt_avail[shirt_index(v [p].choice2)]) {
        shirt_avail[shirt_index(v [p].choice2)]--;
        bktk (p + 1);
        shirt_avail[shirt_index(v [p].choice2)]++;
    }
}
 
int main ()
{
    int t;
    scanf("%d", &t);
 
    while (t--) {
        scanf("%d %d", &n, &m);
 
        for (int i = 0; i < m; i++) scanf("%s %s", v [i].choice1, v [i].choice2);
 
        reset(n / 6);
 
        possible = false;
        bktk(0);
 
        if (possible) printf ("YES\n");
        else printf ("NO\n");
    }
 
    return 0;
}
