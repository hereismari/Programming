#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX2 100
#define ll long long int

using namespace std;

int t, n, k;
ll res;
ll l[MAX2];
bool freq[MAX2];

int main() {

    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++) {

        res = 0;

        scanf("%d %d",&n,&k);
        for(int j = 0; j < n; j++){
            scanf("%lld",&l[j]);
            freq[j] = true;
        }

        int x = 30;

        while((1 << x) >= 0) {
            ll test = 1 << x;
            int cont = 0;

            for(int j = 0; j < n; j++){
                if(freq[j] && ((l[j] & test) != 0)) cont++;
            }

            if(cont >= k) {
                for(int j = 0; j < n; j++)
                    if(freq[j] && ((l[j] & test) == 0)) freq[j] = false;
                res += test;
            }
            x--;
        }

       printf("%lld\n",res);
    }

    return 0;
}
