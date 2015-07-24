#include <bits/stdc++.h>
#define ll long long
#define ppi pair<int, int>
#define MAX 100010

struct calc{
	int begin,end;
	calc(int begin=0,int end=0){
		this->begin = begin;
		this->end = end;
	}
	bool operator < (const calc & other) const{
		if(begin != other.begin) return begin < other.begin;
		return end < other.end;
	};
};

using namespace std;

int t;
int n,c;
calc calcada[MAX];
int estrela[MAX];
int e,a,b;

int cont;

int main(){
	
	scanf("%d",&t);
	for(int k = 0 ; k < t ; k++){
		scanf("%d %d",&n,&c);
		for(int j = 0 ; j < c ; j++){
			scanf("%d %d",&a,&b);
			calcada[j] = calc(a,b);
		}

		scanf("%d",&e);
	
		int cont = 0;
		for(int j = 0 ; j < e ; j++) scanf("%d",&estrela[j]);
		
		sort(calcada,calcada + c);
		sort(estrela,estrela + e);
	
		for(int i = 0, j = 0; j < e; ){
			if(i > c) break;
			else if(calcada[i].begin <= estrela[j] && calcada[i].end >= estrela[j]){
				cont++;
				j++;
			}
			else if(calcada[i].end < estrela[j]) i++;
			else if(calcada[i].begin > estrela[j]) j++;
		}

		printf("Caso #%d: %d\n",k+1,cont);
	}

	return 0;
}
