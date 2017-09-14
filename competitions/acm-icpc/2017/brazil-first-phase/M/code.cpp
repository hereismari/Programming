#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int a, b, c;
	cin >> a >> b >> c;
	
	cout << min(2*b + 4*c, min(2*a+2*c, 2*b+4*a)) << endl;
	
	return 0;
}

