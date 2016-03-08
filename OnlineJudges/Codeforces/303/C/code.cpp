#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	int n;
	ll x,h;
	ll pre_x, pre_h;
	bool pre = true;
	scanf("%d",&n);
	
	ll answer = 2;
	if(n == 1) answer = 1;
	scanf("%lld %lld",&pre_x,&pre_h);
	for(int i = 1; i < n; i++){
		scanf("%lld %lld",&x,&h);
		if(!pre && (x - pre_x) > pre_h + h){
			pre = true;
			answer += 2;
		}
		else if(!pre && (x - pre_x) > pre_h){
			pre = false;
			answer += 1;
		}
		else if(x - pre_x > h){
			pre = true;
			answer += 1;
		}
		else { pre = false;}

			pre_h = h;
			pre_x = x;
	}
	if(pre && n != 1) answer -= 1;
	printf("%lld\n",answer);
	return 0;
}
