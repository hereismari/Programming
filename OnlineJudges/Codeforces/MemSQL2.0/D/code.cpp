#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
#define msi multiset<int>

using namespace std; 

int k, n1,n2,n3,t1,t2,t3;

int main() {
	
	scanf("%d %d %d %d %d %d %d",&k,&n1,&n2,&n3,&t1,&t2,&t3);

	int answer = 0;	
	msi wash;
	msi dry;
	msi fold;
	
	for(int i = 0; i < n1; i++) wash.insert(0);
	for(int i = 0; i < n2; i++)	dry.insert(0);
	for(int i = 0; i < n3; i++) fold.insert(0);

	for(int i = 0; i < k; i++) {
		int aux1 = *wash.begin(); wash.erase(wash.begin());
		int in1 = aux1 + t1;
		wash.insert(in1);

		int aux2 = *dry.begin(); dry.erase(dry.begin());
		int in2 = max(in1,aux2) + t2;
		dry.insert(in2);
	
		int aux3 = *fold.begin(); fold.erase(fold.begin());
		int in3 = max(in2,aux3) + t3;
		fold.insert(in3);
		
		answer = in3;
	}

	printf("%d\n",answer);
	return 0;
}
