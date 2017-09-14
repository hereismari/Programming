#include <bits/stdc++.h>

using namespace std;

int main() {

	// notas
	vector<string> v;
	
	v.push_back("do");
	v.push_back("do#");
	
	v.push_back("re");
	v.push_back("re#");
	
	v.push_back("mi");
	
	v.push_back("fa");
	v.push_back("fa#");
	
	v.push_back("sol");
	v.push_back("sol#");
	
	v.push_back("la");
	v.push_back("la#");
	
	v.push_back("si");
	
	// padrao
	vector<int> p;
	
	p.push_back(2);	
	p.push_back(2);
	
	p.push_back(1);
	
	p.push_back(2);
	p.push_back(2);
	p.push_back(2);
	
	p.push_back(1);

	map<int, string> teclado;
	for(int i = 1; i <= 61; i++) {
		teclado[i] = v[(i-1) % v.size()];
		// cout << i << " " << v[(i-1) % v.size()] << "\n";
	}
	
	set<string>s[13];
	for(int i = 1; i <= 12; i++) {
		int cont = i;
		s[i].insert(teclado[cont]);
		//cout << teclado[i] << endl;
		for(int j = 0; j < p.size(); j++) {
			cont += p[j];
			s[i].insert(teclado[cont]);
			//cout << teclado[cont] << " ";
		}
		//cout << endl;
	}
	
	int n;
	scanf("%d", &n);
	
	int a[n];
	for(int i = 0; i < n; i++) {
		scanf(" %d", &a[i]);
	}
	
	string ans = "desafinado";
	for(int i = 1; i <= 12; i++) {
		bool flag = true;
		for(int j = 0; j < n; j++) {
			if(s[i].find(teclado[a[j]]) == s[i].end()) {
				flag = false;
				break;
			}
		}
		if(flag) { ans = teclado[i]; break; }
	}
	
	cout << ans << endl;
	
	return 0;
}


