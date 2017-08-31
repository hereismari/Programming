#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	char c;
	stack<char> k;
	
	int i = 0;
	while(scanf("%c",&c) != EOF){
		if(c == ' ' || c == '\n'){
			while (!k.empty()) {printf("%c",k.top()); k.pop();}
			printf("%c",c);
		}
		else k.push(c);
	}
	while (!k.empty()) printf("%c",k.top()); k.pop();
	return 0;
}
