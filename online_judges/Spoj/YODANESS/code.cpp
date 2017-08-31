#include <stdio.h>
#include <map>
#include <string>
#define MAX 10000000
#define LIM 30011
#define ll long long int

using namespace std;

map<string, int> m;
int a[MAX];
int tmp[MAX];
int  n;
char c;
ll cont;
int k;
char s[LIM];

ll merge(int a[], int tmp[],int b, int m, int e){

	for(int i = b ; i <= e ; i++)
		tmp[i] = a[i];
	
	int l = b;
	int i = b;
	int r = m+1;
	ll invcont = 0;

	while(l <= m && r <= e){
		if(tmp[l] <= tmp[r]) a[i] = tmp[l++];
		else { invcont += (m+1-l); a[i] = tmp[r++];}
		i++;
	}	

	while(l <= m){ a[i] = tmp[l++]; i++;}
	while(r <= e){ a[i] = tmp[r++]; i++;}

	return invcont;
}

ll sort( int a[], int tmp[], int b, int e){
	ll invcont = 0;
	if(b < e){
		int m = (b+e)/2;
		invcont += sort(a,tmp,b,m);
		invcont += sort(a,tmp,m+1,e);
		invcont += merge(a,tmp,b,m,e);
	}

	return invcont;
}

int main(){

	scanf("%d\n",&n);
	for(int i = 0 ; i < n ; i++){
			scanf("%d",&k);
			for(int j = 0 ; j < k ; j++){
				scanf("%s",s);
				m[s] = j;
			}
			for(int j = 0 ; j < k ; j++){
				scanf("%s",s);
				a[j] = m[s];
			}
	
		printf("%lld\n",sort(a,tmp,0,k-1));
	}
	
	return 0;
}
