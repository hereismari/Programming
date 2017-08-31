#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	char c;
	int i = 0;
	while(scanf("%c",&c) != EOF){
		if(c == '"' && i % 2 == 0) {printf("``"); i++; }
		else if (c == '"') {printf("''"); i++;}
		else printf("%c",c);
	}

	return 0;
}
