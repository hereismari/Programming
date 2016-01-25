#include <bits/stdc++.h> 

#define MAX 100100
#define DIST_MAX 202
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

struct leg {

	int length, value;
	leg() { length = 0; value = 0;}
	bool operator < (const leg & l) const {
		return length < l.length;
	}
};

int n, m, x, y, sum[MAX], dist[DIST_MAX];
leg l[MAX];
map<int,int> quant;
int answer;

int calculate(int length, int last_index) {
	
    int size = n - (quant[length] * 2 - 1);
	size -= (n - last_index - 1);	
	
    int result = sum[n-1] - sum[last_index];
	
    int i = 1;
	while(size > 0 && i < DIST_MAX){
		result += min(size, dist[i]) * i;
		size -= min(size, dist[i]);
		i++;
	}
	
    return result;
}

int main() {
 
	scanf("%d",&n);

	for(int i = 0; i < n; i++) {
		scanf("%d",&x); 
        l[i].length = x;
		if(quant.find(x) != quant.end()) quant[x] += 1;
		else quant[x] = 1;
	}

	for(int i = 0; i < n; i++){
		scanf("%d",&x); l[i].value = x;
	}

	if(n == 1 || (n == 2 && l[0].length == l[1].length)) { printf("0\n"); return 0; }
	else if(n == 2) { printf("%d\n",min(l[0].value,l[1].value)); return 0; }

	sort(l, l + n);
	memset(sum, 0, sizeof sum);
	memset(dist, 0, sizeof dist);
	answer = INT_MAX;
	
	for(int i = 0; i < n; i++) sum[i] = l[i].value;
	for(int i = 1; i < n; i++) sum[i] += sum[i-1];
	
	for(int i = 0; i < n;) {
	    int length = l[i].length; 
        int j = i;
		while(l[j].length == length && j < n) j++;
		answer = min(answer,calculate(length, j - 1));
		while(i < j) { dist[l[i].value]++; i++; }
	}

	printf("%d\n", answer);
	return 0; 
}
