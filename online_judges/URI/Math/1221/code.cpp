#include <stdio.h>
#include <math.h>
#include <bitset>
#include <vector>

#define ll long long int
#define MAX 1000000

using namespace std;

int k;
ll n;
bitset<MAX+10> bs;
vector<int> primes;

void generate_primes(ll upperbound)
{
	bs.reset();
	bs.flip();
	bs.set(0,false); bs.set(1,false);
	for(ll i = 2; i <= upperbound+1; i++) 
		if(bs.test((i))){
			for(ll  j = i * i ; j <= upperbound+1; j += i)
				bs.set(j,false);
		primes.push_back((int)i);
	}
	
}

bool isPrime(ll n){

	if(n < MAX) return bs.test(n);
	for(ll i = 0; i <primes.size(); i++) if (n % primes[i] == 0) return false;
	return true;
} 

int main(){
	generate_primes(MAX);
	scanf("%d",&k);
	while(k > 0){
	k--;
	scanf("%lld",&n);
	printf("%s\n", isPrime(n) ? "Prime": "Not Prime");
	}

	return 0;
}
