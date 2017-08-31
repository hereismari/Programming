#include <bits/stdc++.h> 

#define MAX 1000100 
#define MOD 1000000007
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x;
int reset[MAX];
set<int> st;

void preprocess(string t){

	reset[0] = -1;
	int j = -1;
	for(int i = 1; i < t.length(); i++){
		while(j >= 0 && t[j+1] != t[i]) j = reset[j];
		if(t[j+1] == t[i]) j++;
		reset[i] = j;
	}
}

void updateSet(int l){
	int j = l-1;
    while(reset[j] >= 0){
        j = reset[j];
        st.insert(j+1);
    }
}

int main() {
	
	scanf("%d %d",&n,&m);
	
	string s;
	cin >> s;
	int l = s.length();
    
	preprocess(s);
	updateSet(l);

	ll empty = 0, j = 0;
    for(int i = 0; i < m; i++){
        scanf("%d",&x);
        if (x > j) empty += (x-j-1);
        else if(!st.count(j - x + 1)){
            printf("0\n");
            return 0;
        }
        j = x + l - 1;
    }

    empty += n - j;
    ll ans = 1;
    for(int i = 0; i < empty; i++)
		ans= (ans * 26ll ) % MOD;
   
	printf("%lld",ans); 
	return 0; 
}
