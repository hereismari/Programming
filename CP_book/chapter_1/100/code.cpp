#include <bits/stdc++.h>
#define ll long long int

using namespace std;
 
int main() {
	
    int a, b;
 
    while (scanf("%d %d", &a, &b) != EOF) {
 
        int temp_a = a;
        int temp_b = b;
 
        if (a > b) swap (a, b);
 
        int mcl = 0;
        int cl;
 
        while (a <= b) {
            ll n = a; cl= 1;
 
            while (n != 1) {
                if (n % 2 == 1) n = 3 * n + 1;
                else n /= 2;
                cl++;
            }
 
            if (cl > mcl) mcl = cl;

            a++;
        }
 
        printf ("%d %d %d\n", temp_a, temp_b, mcl);
    }
 
    return 0;
}
 

