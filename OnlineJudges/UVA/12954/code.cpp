#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

ll n,m,x,y;

ll binSearch() {
    
    ll i = 0LL, j = n/2LL;
    while(i <= j) {
        
        ll mid = (i+j)/2LL;
        ll check = 4LL*mid*(n-mid);
        if(check <= m) i = mid + 1LL;
        else j = mid - 1LL;

    }

    return i;
}

int dir_x[] = {0, 1, 0, -1};
int dir_y[] = {1, 0, -1, 0};

int main() {
 
    while(scanf("%lld %lld", &n, &m) != EOF){

        ll num_cicles = binSearch() - 1LL;
        m -= 4LL*num_cicles*(n-num_cicles);

        ll x = num_cicles + 1LL, y = num_cicles;
        ll side_len = n - num_cicles*2LL;

        int d = 0;
        while(m > 0LL){
            x += dir_x[d]*min(m,side_len);
            y += dir_y[d]*min(m,side_len);

            m -= side_len;
            if(!d) side_len--;
            d++;
        }

        printf("%lld %lld\n", x, y);
    }

	return 0; 
}
