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

struct island{

	ll dist1, dist2, to, from;
	island(ll dist1=0, ll dist2=0,ll from=0, ll to=0){
		this->dist1 = dist1;
		this->dist2 = dist2;
		this->from = from;
		this->to = to;
	}

	bool operator < (const island & other) const {
		if(dist2 != other.dist2) return dist2 < other.dist2;
		return dist1 < other.dist1;
	}

};

ll n, m, x[MAX], y[MAX];
ll aux;
multimap<ll, int> b;
island is[MAX];
ll answer[MAX];

int main() {
 
	scanf("%lld %lld",&n,&m);
	for(int i = 0; i < n; i++)
		scanf("%lld %lld",&x[i],&y[i]);
	for(int j = 0; j < m; j++){
		scanf("%lld",&aux);
		b.insert(mp(aux,j+1));
	}

	for(int i = 0; i < n-1; i++) {
		ll dist1 = x[i+1] - y[i];
		ll dist2 = y[i+1] - x[i];
		is[i] = island(dist1,dist2,i+1,i+2);
	}

	sort(is,is+n-1);
	memset(answer,-1,sizeof answer);

	for(int i = 0; i < n-1; i++){

		multimap<ll,int>::iterator it = b.lower_bound(is[i].dist1);
		//printf("%lld %lld %lld",is[i].dist1,is[i].dist2,it->second);
		if(it != b.end() && it->first <= is[i].dist2) {
			answer[is[i].from-1] = it->second;
			b.erase(it);
		}
		else
			{printf("No\n"); return 0;}
	}

	for(int i = 0; i < n-1; i++)
		if(answer[i] == -1) {printf("No\n"); return 0;}

	printf("Yes\n");
	for(int i = 0; i < n-1; i++)
		printf("%lld ",answer[i]);

	return 0; 
}
