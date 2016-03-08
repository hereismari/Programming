#include <bits/stdc++.h>
#define MAX 2001010

#define ll long long int
using namespace std;

int n;
ll a[MAX];
bool visited[MAX];

ll gcd(ll a, ll b) {
	long long t;
	while (a % b)
		t = a, a = b, b = t % b;
	return b;
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll permutationSorting() {

   memset(visited, false, sizeof visited);
	ll ans = 1;
    for(int i = 0; i < n; i++){
        if(!visited[i] && i != a[i]){
            ll cont = 0;
            ll aux = i;
            while(!visited[aux]){
                cont++; visited[aux] = true; aux = a[aux];
            }
 			ans = lcm(ans,cont);
        }
    }
    return ans;
}

int bruteforce() {
    bool done = false;
    int b[MAX], cont = 0;
    while(!done){
        cont++;
        for(int i = 1,j=1; i <= n/2; i+=1,j+=2){
            b[j] = a[n/2+i];
            b[j+1] = a[i];
        }
        bool flag = true;
        for(int i = 1; i <= n; i++){
//            printf("%d ",b[i]);
            a[i] = b[i];
            if(a[i] != i) flag = false;
        }
        done = flag;
    }

    return cont;
}

int main() {

    while(scanf("%d",&n) != EOF) {

        for(int i = 0; i < n; i++) {
            if(i % 2 == 1) a[i] = i/2;
            else a[i] = i/2 + n/2;
        }

        ll ans = permutationSorting();
        printf("%lld\n",ans);
    }

    return 0;
}
