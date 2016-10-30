#include <stdio.h>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long int
#define INF 1000000000

#define mp make_pair 
#define pb push_back
#define F first
#define S second

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    vector<ll> v[m+1];
    vector< pair<int, pair<int,ll> > > max_v[n+1];
    for(int i = 0; i <= n; i++) v[0].pb(0);

    int op[m], l[m], r[m];
    ll x[m];

    int id = 1, id_op = 1;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d %lld", &op[i], &l[i], &r[i], &x[i]);
        if(op[i] == 1) {
            v[id].pb(0);
            for(int j = 1; j <= n; j++) {
                if(j >= l[i] && j <= r[i])
                    v[id].pb(v[id-1][j] + x[i]);
                else
                    v[id].pb(v[id-1][j]);
            }
            id++;
        }
        else {
            for(int j = l[i]; j <= r[i]; j++) {
                max_v[j].pb(mp(id_op, mp(id-1, x[i])));
            }
            id_op++;
        }
    }


    for(int i = 0; i < id; i++) {
        for(int j = 0; j < v[i].size(); j++)
            printf("%lld ", v[i][j]);
        printf("\n");
    }

/*    printf("------------------\n");

    for(int i = 0; i <= n; i++) {
        printf("%d\n", i);
        for(int j = 0; j < max_v[i].size(); j++)
            printf("%d, %lld\n", max_v[i][j].S.F, max_v[i][j].S.S);
        printf("\n");
    }
*/
    ll answer[n+1];
    set<int> s;
    answer[0] = 0LL;

    for(int i = 1; i <= n; i++) {
        ll res = INF * -1LL;
        int k = 0;
        while(k < max_v[i].size()) {
            if(s.find(max_v[i][k].F) != s.end()) {
                k++;
            }
            else {                
                res = max_v[i][k].S.S;
                break;
            }
        }

        //printf("%d %lld\n", i, res);
		
        k = max(k-1, 0);
        for(int j = k+1; j < max_v[i].size(); j++) {
            int id_exp = max_v[i][j].S.F;
            ll max_exp = max_v[i][j].S.S;
            if(res + v[id_exp][i] <= max_exp) continue;
            else { k = j; res = max_exp; }
        }
        
        if(res != INF * -1LL) {
        	s.insert(max_v[i][k].F);
        	answer[i] = res - v[max_v[i][k].S.F][i]; 
        }
        else {
        	answer[i] = res;
        }
    }

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

