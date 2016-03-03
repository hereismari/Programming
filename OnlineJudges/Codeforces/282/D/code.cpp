#include <bits/stdc++.h> 

#define MOD 1000000007
#define MAX 100100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int reset[MAX];
int b[MAX];
ll dp1[MAX];
ll dp2[MAX];

void preprocess(string t){

	reset[0] = -1;
	for(int i = 1; i <= t.length(); i++){
		int j = reset[i-1];
		while(j >= 0 && t[j] != t[i-1]) j = reset[j];
		reset[i] = j + 1;
	}
}

int KMP(string s, string t){
	
	preprocess(t);
	int m = t.length(), n = s.length();
	int i = 0, j = 0;
	b[0] = -1;
	while(i < n){
		while (j>=0 && s[i] != t[j]) j = reset[j];
        i++; j++;
        if (j == m) {
            b[i-m] = i;
            j = reset[j];
        }
	}
}

int main() {
 
	string s,t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	memset(b,-1,sizeof b);
	KMP(s,t);

	for(int i = n -1, k = -1; i >= 0; i--){
		if(b[i] != -1) k = b[i];
		b[i] = k;
	}

	for(int i = n-1; i >=0; i--){
		if(b[i] != -1) { 
			dp1[i] = (dp1[i+1] + dp2[b[i]] + 1 + (n - b[i])) % MOD;
			dp2[i] = (dp2[i+1] + dp1[i]) % MOD;
		}
		else dp1[i] = 0;
	}

	printf("%lld\n",dp1[0]);	
	return 0; 
}
