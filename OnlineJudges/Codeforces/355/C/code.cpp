#include <bits/stdc++.h>

#define BASE 2
#define MAX 100000
#define MOD 1000000007
#define ll long long int 

using namespace std;

int ones;

string toBASE(ll n) {
    int x = 0;
    char aux[MAX];
    char c;
    while(n >= 1) {
        c = n % BASE < 10 ?(n % BASE + '0') : ((n % BASE) - 10 + 'A');
        n /= BASE;
        if (c == '1') ones++;
        aux[x++] = c;
    }
  
    string s = "";
    for(int i = x-1; i >=0 ; i--) s += aux[i];
    return s;
}

int getValue(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	else if('A' <= c && c <= 'Z') return c - 'A' + 10;
	else if('a' <= c && c <= 'z') return c - 'a' + 36;
	else if(c == '-') return 62;
	else return 63;
}

int main() {

	string s;
		cin >> s;
		
		int total = 0;
		int total_ones = 0;
		
		for(int i = 0; i < s.size(); i++) {
			
            ones = 0;
			
			int v = getValue(s[i]);
            string s2 = toBASE(v); 
			total += 6;
			total_ones += ones;
		}
		
		int total_zeros = total - total_ones;
        ll ans = 1;
		for(int i = 0; i < total_zeros; i++)
			ans = (ans * 3) % MOD;
		
        printf("%lld\n", ans);

	return 0;
}
