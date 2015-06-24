#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define ALPHA 26
using namespace std;

int n;
int l,k;
int cont;

string s1;
string s2;

int m[ALPHA][ALPHA];
int main(){
	
	for(int i = 0; i < ALPHA ; i++)
		for(int j = 0 ; j < ALPHA ; j++)
			m[i][j] = -1;
	
	scanf("%d",&n);
	cin >> s1;
	cin >> s2;
	cont = 0;
	for(int i = 0; i < n ;i++){
		if(s1[i] != s2[i]){
			cont++;
			m[s1[i]-'a'][s2[i]-'a'] = i+1;
		}
	}

	for(int i = 0 ; i < ALPHA; i++)
		for(int j = i+1; j< ALPHA; j++)
				if(m[i][j] > 0 && m[j][i] > 0){
				printf("%d\n%d %d\n",cont-2,m[i][j],m[j][i]);
				return 0;}

	for(int i = 0; i < ALPHA; i++){
		l = 0;
		for(int j = 0; j < ALPHA ; j++)
			if(i != j && m[i][j] > 0)
				l = m[i][j];
		
		if(l != 0){
		for(int j = 0; j < ALPHA; j++)
			if(i!=j && m[j][i] > 0){
				printf("%d\n%d %d\n",cont-1,l,m[j][i]);
				return 0;}
		}
	}
		
	printf("%d\n%d %d\n",cont,-1,-1);
	return 0;
}

