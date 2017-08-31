#include <bits/stdc++.h>
#define BLACK 'B'
#define WHITE 'W'
#define mp make_pair
#define pb push_back
#define color second
#define q first
#define ll long long
using namespace std;

int main() {

    int t, n;
	scanf("%d", &t);
	
	while(t--) {

		vector< pair <ll, char> > pedras;
		map<char, ll> need;
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++) {
			char c;
			int qt;
			scanf("%d %c", &qt, &c);
			need[c] += qt;
			pedras.pb(mp(qt, c));
		}
		
        ll ans = 0;
	    ll g = __gcd(need[WHITE], need[BLACK]);
		if(need[WHITE] == 0) cout << need[BLACK] << endl;
		else if(need[BLACK] == 0) cout << need[WHITE] << endl;
		else {
			for(int i = 0; i <n ;i++) {
				char c = pedras[i].color;
				char other_c = c == BLACK ? WHITE : BLACK; 
	    			if (m[other_c] % need[other_c]) m[c] += pedras[i].q;
	    			else {
	    				if (m[c]/need[c] < m[other_c]/need[other_c] && m[c]/need[c] <= (m[c] + pedras[i].q)/need[c]) ans++;
	    				m[other_c] += pedras[i].q;
	    			}
	    		}
	    	cout<< ans <<"\n";
		}
	}

	return 0;
}
