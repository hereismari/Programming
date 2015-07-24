#include <bits/stdc++.h> 

#define MAX 2000100
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;

bool cmp(char s1[MAX], char s2[MAX], int len){
	for(int i = 0; i < len; i++)
		if(s1[i] != s2[i]) return false;
	return true;
}

bool verify(char s1[MAX], char s2[MAX], int len){
	
	if(cmp(s1,s2,len)) return true;
	if(len % 2 == 1) return false;
	return (verify(s1,s2 + len/2,len/2) && verify(s1 + len/2,s2,len/2)) || (verify(s1,s2,len/2) && verify(s1+len/2,s2+len/2,len/2));
}

int main() {
 
	char s1[MAX], s2[MAX];
	scanf("%s %s",s1,s2);
	printf("%s\n", verify(s1,s2,strlen(s1)) ? "YES":"NO");

	return 0; 
}
