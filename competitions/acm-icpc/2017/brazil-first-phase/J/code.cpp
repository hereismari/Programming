#include <bits/stdc++.h>

using namespace std;

int main() {
	
	string num;
	cin >> num;
	
	long long unsigned int sum = 0;
	for (unsigned int i = 0; i < num.length(); i++) {
		sum += num[i] - 48;
	}
	
	cout << sum % 3 << endl;
	
	return 0;
}

