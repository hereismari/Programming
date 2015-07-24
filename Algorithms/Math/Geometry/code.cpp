#include <bits/stdc++.h> 

#define MAX 1001
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

struct P {

	int x,y;
	P(int a=0, int b=0) { x = a; y = b; }
	int operator * (const P & a) const { return x*a.y - y*a.x;}
	P operator - (const P & a) const { return P(x-a.x, y - a.y);}
	bool operator < (const P & a) const { return (*this)*a < 0; }
};

P p[MAX];
int maxV, n, v[MAX][MAX], t;

int main() {
 
	int count = 0;
	while(true){
	
		scanf("%d",&n);
		if(n == 0) break;

		p[0].x = p[0].y = 0;
		v[0][0] = 1; 
		maxV = 0;

		for(int i = 1; i <= n; i++)	scanf("%d %d",&p[i].x,&p[i].y);
		sort(p + 1,p + n + 1);
		memset(v,0,sizeof v);
		for(int i = 1; i <= n; i++){
			v[i][0] = 2; // Conecta cada ponto com a origem.
			for(int j = 1; j < i; j++){
				for(int k = 0; k < j; k++)
					if(v[i][j] < v[j][k] && ((p[j]-p[k])*(p[i]-p[j])) < 0)
						v[i][j] = v[j][k];
				if(++v[i][j] > maxV) maxV = v[i][j];
			}
		}
		printf("Teste %d\n%d\n\n",++count,maxV);
	}

	return 0; 
}
