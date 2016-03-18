#include <bits/stdc++.h> 

using namespace std; 

#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

#define MAX 1000100  

int n, m, x, y;

int main() {
 
    while(scanf("%d", &n) != EOF) {
		
		ll a[n];
		for(int i = 0; i < n; i++)
    			scanf("%lld", &a[i]);
		
		sort(a, a + n);

		if(n == 1) { printf("-1\n"); break; }
		if(n == 2) { 
			ll d = a[1] - a[0];
			if(d > 0 && d % 2 == 0) {
				printf("3\n%lld %lld %lld\n", a[0] - d, a[1] - d/2, a[1] + d);
			}
			else if(d > 0) {
				printf("2\n%lld %lld", a[0]-d, a[1] + d);
			}
			else printf("1\n%lld", a[0]);
			break;
		}

		ll dif[n];
		for(int i = 0; i < n-1; i++) dif[i] = a[i+1] - a[i];

		set<ll> s;
		for(int i = 0; i < n-1; i++) s.insert(dif[i]); 

		if(s.size() == 1) {
			if(*(s.begin()) == 0) printf("1\n%lld", a[0]);
			else {
				printf("2\n");
				printf("%lld %lld\n", a[0] - dif[0], a[n-1] + dif[0]);
			}
		}
		else if(s.size() == 2) {

			if(*(s.begin()) == 0 || *(++s.begin()) == 0) { printf("0\n"); }
			else {
				ll mainDiff, otherDiff, pos;
				int cont1 = 0, cont2 = 0;
				for(int i = 0; i < n-1; i++) 
					if(dif[i] == *(s.begin())) cont1++;
					else cont2++;
			
				mainDiff = cont1 < cont2 ? *(++s.begin()) : *(s.begin());
				otherDiff = cont1 >= cont2 ? *(++s.begin()) : *(s.begin());
				 
				for(int i = 0; i < n-1; i++)
					if(dif[i] == otherDiff) { pos = i; }

				//printf("%d %d\n", mainDiff, otherDiff);
				if(cont1 == 1 || cont2 == 1 && (mainDiff * 2 == otherDiff)) {
					printf("1\n");
					printf("%lld", a[pos] + mainDiff);
				}
				else printf("0\n");
			}
		}
		else printf("0\n");
	}

	return 0; 
}
  

