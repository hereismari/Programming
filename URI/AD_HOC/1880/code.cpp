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

bool isPalindrome(string s) {
	int n = s.size();
	int i = 0, j = n-1;
	while(i <= j) {
		if(s[i] != s[j]) return false;
		i++; j--;
	}
	return true;
}

bool base(ll n, int BASE) {
 
    int x = 0;
    char aux[MAX];
    char c;
    while(n >= 1) {
        c = n % BASE < 10 ?(n % BASE + '0') : ((n % BASE) - 10 + 'A');
        n /= BASE;
        aux[x++] = c;
    }
 
    string s = "";
    for(int i = x-1; i >=0 ; i--) s += aux[i];
    return isPalindrome(s);
}

int n,m,x,y;

int main() {
 
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		bool flag = true;
		for(int j = 2; j <= 16; j++){
			if(flag && base(x,j)){
				printf("%d", j); flag = false;}
			else if(base(x,j))
				printf(" %d", j);
		}
		if(flag) printf("-1");
		printf("\n");
	}
	return 0; 
}
