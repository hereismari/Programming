#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX 101
using namespace std;

long long int n;
long long int s,c,r;
long long int x;
vector<double> v;

double t;

int main(){

	scanf("%lld",&n);
	for(int i = 0 ; i < n ; i++){
		t = 0;
		v.clear();
		scanf("%lld %lld %lld",&s,&c,&r);
		
		for(int j = 0 ; j < s ; j++){
			scanf("%lld",&x);
			v.push_back(x);}
		sort(v.begin(),v.end());
	//	for(int j = 0; j < s; j++)
	//		printf("%f ", v[j]);		
		for(int j = 0,x = 0; j < s; j++,x++)
			t += x < c ? 1.0/(v[j]+r) : 1.0/(v[j]);				
		
		printf("%.2f\n",t);
	}	

	return 0;
}
