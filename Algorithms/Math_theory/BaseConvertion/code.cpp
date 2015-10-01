#include <bits/stdc++.h>
#define BASE 16
#define MAX 100000
#define ll long long int 

using namespace std;

ll toNumber(string s) {
	int aux = 1;
	ll result = 0;
	for(int i = s.size() - 1; i >= 0; i--){
		result += aux*(s[i]-'0');
		aux *= 10;
	}
	return result;
}

string toBASE(ll n) {
    int x = 0;
    char aux[MAX];
    char c;
    while(n >= 1) {
        c = n % BASE < 10 ?(n % BASE + '0') : ((n % BASE) - 10 + 'A');
        n /= BASE;
        aux[x++] = c;
    }
  
    string s = "";
    for(int i = x-1; i >=0 ; i--) s += aux[i];
    return s;
}

ll fromBASE(string s){

   int t = s.size()-2;
   int j = 0;

   ll valor=0;   
   for(int i=2,j = 0; i<s.size(); i++, j++){
         if(s[i] >= '0' && s[i] <= '9')
            valor += (s[i] - '0') * pow(BASE, t-j-1);
         else
            valor += (s[i] - 'a' + 10) * pow(BASE, t-j-1);
   }

   return valor;
}

int main() {

	string s;
	while(true) {
		cin >> s;
		if(s[0] == '-') break;
		if(s.size() < 1 || s[1] != 'x') cout << "0x" << base16(toNumber(s)) << '\n';
		else cout << base10(s) << '\n';
	}	

	return 0;
}

