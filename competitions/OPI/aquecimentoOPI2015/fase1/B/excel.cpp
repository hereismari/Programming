#include <stdio.h>
#include <string>
#include <iostream>
#define ll long long int

using namespace std;

string answer(ll n) {

    string result = "";
    while (n > 0) {
      n--;
      int r = n % 26;
      char digit = (char) (r + 'A');
      result = digit + result;
      n = (n - r) / 26;
    }
    return result;
}

int main() {

	ll x,y;
	while(true)	{
		scanf("\nR%lldC%lld",&x,&y);
		if(x == 0 && y == 0) break;
		cout << answer(y) << x << "\n";
	}
	return 0;
}
