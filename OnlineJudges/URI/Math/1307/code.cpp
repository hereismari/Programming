#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#define ll long long int
#define max(a,b) (a >= b ? a : b)
#define min(a,b) (a < b ? a : b) 

using namespace std;

ll n;
ll n1, n2;

ll mdc(ll a, ll b){

	ll rest;
	while((rest = a % b) != 0){
		a = b;
		b = rest;
	}

	return b;
}

ll convert(string s1){
	ll dec = 0;
	reverse(s1.begin(), s1.end());
	for (int i = 0 ; i < s1.size() ; ++i) 
		dec += (int(s1[i]) - 48)*pow(2, i);
	return dec;
}

int main(){
	string bin1,bin2;
	scanf("%lld",&n);
	for(int i = 0 ; i < n; i++){
		cin >> bin1;
		cin >> bin2;
		n1 = convert(bin1);
		n2 = convert(bin2);
//		printf("%lld %lld\n", n1,n2);
		if(mdc(max(n1,n2),min(n1,n2)) != 1)
			printf("Pair #%d: All you need is love!\n",i+1);
		else
			printf("Pair #%d: Love is not all you need!\n",i+1);
	}
	return 0;
}
