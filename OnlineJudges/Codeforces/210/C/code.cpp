#include <stdio.h>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

#define ll long long int
#define INF 1000000000

#define mp make_pair 
#define pb push_back
#define F first
#define S second

#define HELPER 50000001

struct operation {
    int l, r, maxi, id;
    operation(int l=0, int r=0, int maxi=0, int id=0) {
        this->l = l;
        this->r = r;
        this->maxi = maxi;
        this->id = id;
    }
};

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    vector<ll> v[m+1];
    vector<operation> ops;
    vector< pair<int, pair<int,ll> > > max_v[n+1];
    for(int i = 0; i <= n; i++) v[0].pb(0);

    // store the queries
    int op[m], l[m], r[m];
    ll x[m];
    int counter[n+1];

    memset(counter, 0, sizeof counter);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %lld", &op[i], &l[i], &r[i], &x[i]);
        if(op[i] == 1) {
            for(int j = l[i]; j <= r[i]; j++)
                counter[j]++;
            x[i] += HELPER;
        }
    }

    ll answer[n+1];
    bool used[n+1];
    for(int i = 0; i <= n; i++) {
        used[i] = false;
        answer[i] = -50000000;
    }
    // execute the queries backward
    for(int i = m-1; i >= 0; i--) {
        if(op[i] == 1) {
            for(int j = l[i]; j <= r[i]; j++) {
                answer[j] -= x[i];
            }
        }
        else {
            for(int j = l[i]; j <= r[i]; j++)
                if(!used[j]) {
                    answer[j] = x[i];
                    used[j] = true;
                    break;
                }
        }
    }

/*    printf("------------------\n");

    for(int i = 0; i <= n; i++) {
        printf("%d\n", i);
        for(int j = 0; j < max_v[i].size(); j++)
            printf("%d, %lld\n", max_v[i][j].S.F, max_v[i][j].S.S);
        printf("\n");
    }
*/
     printf("YES\n");
    for(int i = 1; i <= n; i++) printf("%lld ", answer[i] + HELPER * counter[i]);
    printf("\n");
 
    ll aux[n+1];
    for(int i = 0; i <= n; i++) aux[i] = answer[i];

    for(int i = 0; i < m; i++) {
        if(op[i] == 1) {
            for(int j = l[i]; j <= r[i]; j++)
                aux[j] += x[i];
        }
        else {
            ll max_aux = 0;
            for(int j = l[i]; j <= r[i]; j++) 
                max_aux = max(max_aux, aux[j]);
            if(max_aux != x[i]) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    for(int i = 1; i <= n; i++) printf("%lld ", answer[i]);
    printf("\n");

    return 0;
}

