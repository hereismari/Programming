#include <bits/stdc++.h> 

#define MAa[0] 1000100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int main() {

	int x[3];

	while(scanf("%d %d %d", &x[0], &x[1], &x[2]) == 3 && x[0]) {

		bool is_set = false, is_pair = false;
		int a, b, c, unmatched;

		sort(x, x + 3);

		a = x[0], b = x[1], c = x[2];

		if(a == b && b == c) is_set = true;
		
		else if(a == b || b == c){
			is_pair = true;
			if(a == b) unmatched = c;
			else unmatched = a;
		}
		if(is_set && a == 13) puts("*");
		else if(is_set) printf("%d %d %d\n", a + 1, a + 1, a + 1);
		else if(is_pair){
			if(b == 13 && unmatched == 12) puts("1 1 1");
			else {
				while(true) {
					unmatched = unmatched + 1;
					if(unmatched == 14){
						unmatched = 1;
						b++;
					}
					if(unmatched != b) break;
				}
				x[0] = x[1] = b;
				x[2] = unmatched;
				sort(x, x + 3);
				printf("%d %d %d\n", x[0], x[1], x[2]);

			}
		} else puts("1 1 2");

	}
	return 0;
}
