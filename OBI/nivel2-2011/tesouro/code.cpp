#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int x,y,v;

int d[MAX];
pair <int,int> p[MAX];

int xres,yres;

int dist(int x1, int x2, int y1, int y2){
	return abs(x1-x2) + abs(y1-y2);
}

int answer(int n, int k){
	bool aux;
	int cont = 0;
	for(int i = n-1; i >= 0 ; i--)
		for(int j = 0; j < n; j++){
			aux = false;
			for(int x = 0; x < k; x++){
				aux = dist(j,p[x].first,i,p[x].second) == d[x];
				if(aux == false) break;
			}
			if(aux){cont++;xres = j;yres=i;}
		}

	return cont;
}

int main(){

	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 0 ; i < k ; i++){
		scanf("%d %d %d",&x,&y,&v);
		d[i] = v;
		p[i] = make_pair(x,y);
	}

	int res = answer(n,k);
	if(res == 1) printf("%d %d\n",xres,yres);
	else printf("-1 -1\n");

	return 0;
}
