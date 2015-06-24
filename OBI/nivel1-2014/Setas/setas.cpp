#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
using namespace std;

int n;
int l,k;
int cont;

map < char, vector<int> > e1;
map < char, vector<int> > e2;
set <char> marked;
map < pair<int, int> , int > saida;

string s1;
string s2;

int maior;

int main(){
	
	scanf("%d",&n);
	cin >> s1;
	cin >> s2;
	cont = 0;
	for(int i = 0; i < n ;i++){
		if(s1[i] != s2[i]){
			cont++;
			marked.insert(s1[i]);
			marked.insert(s2[i]);
			e1[s1[i]].push_back(i+1);
			e2[s2[i]].push_back(i+1);
		}
	}
	for(std::set<char>::iterator it=marked.begin(); it!=marked.end(); ++it)	
	{
		if(e1.count(*it) != 0 && e2.count(*it)!= 0){
			for(int i = 0; i < e1[*it].size();i++)
				for(int j=0;j< e2[*it].size();j++){
					saida[make_pair(e1[*it][i],e2[*it][j])]++;
					saida[make_pair(e2[*it][j],e1[*it][i])]++;
			}
		} 
	}
	
	maior = 0;
	l = k = -1;
	for(std::map< pair<int,int>, int>::iterator it=saida.begin(); it!=saida.end(); it++){
		if(it->second > maior){
		maior = it->second;
		l = (it->first).first;
		k = (it->first).second;
		}
	}
	printf("%d\n%d %d\n",cont - maior,l,k);
	return 0;
}
