#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;

string input;
char c;
list<char> s;
list<char> aux;

bool state1,state2;
int main(){

	while(1){
		state1 = true;
		state2 = false;
		s.clear();
		aux.clear();			
	getline(cin,input);
	for(int i = 0; i < input.size(); i++){
		c = input[i];	
		if(c == '[') {s.insert(s.begin(),aux.begin(),aux.end()); aux.clear();state2 = true; state1 = false;}
		else if (c == ']') { s.insert(s.begin(),aux.begin(),aux.end());
			aux.clear(); state1 = true; state2 = false;}
		else{
			if(state1) s.push_back(c);
			else aux.push_back(c);
		}
	}
	s.insert(s.begin(),aux.begin(),aux.end());
	for(list<char>:: iterator i = s.begin() ; i != s.end(); i++)
		printf("%c",*i);
	if(s.size() > 0 && cin)printf("\n");	
	
	if (!cin) break;	
}

	return 0;
}
