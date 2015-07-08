#include <bits/stdc++.h>

using namespace std;

struct gamer{

	char name[50];
	int pos;
	int pont;
	int gol;
	int victory;

};

bool comp(gamer g1, gamer g2){

	if(g1.pont > g2. pont) return true;
	if(g1.pont < g2.pont) return false;

	if(g1.victory > g2.victory) return true;
	if(g1.victory < g2.victory) return false;

	if(g1.gol > g2.gol) return true;
	if(g1.gol < g2.gol) return false;

	return g1.pos < g2.pos;
}

int main(){

	int k, n, m;
	char x[50],y[50];
	int p1,p2;
	gamer game[10000];
	scanf("%d",&k);
	
	for(int i = 0 ; i < k ; i++){
	
		scanf("%d %d",&n,&m);
		for(int j = 0; j < n; j++){
			scanf("%s",game[j].name);
			game[j].pos = game[j].pont = game[j].victory = 0;
			game[j].pos = j;
		}

		for(int j = 0 ; j < m; j++){
			scanf("%d %s %d %s",&p1,x,&p2,y);
			int i1, i2;
			for(int l = 0; l < n; l++){
				if(strcmp(game[l].name,x) == 0){
					game[l].gol += p1;
					i1 = l;
				}
				if(strcmp(game[l].name,y) == 0){
					game[l].gol += p2;
					i2 = l;
				}
			}

			if(p1 > p2){
				game[i1].victory += 1;
				game[i1].pont += 3;
			}
			else if(p1 < p2){
				game[i2].victory += 1;
				game[i2].pont += 3;
			}
			else{
				game[i1].pont += 1;
				game[i2].pont += 1;
			}
	}

	sort(game,game +n,comp);
	for(int j = 0; j < n; j++)
		printf("%s\n",game[j].name);

	}

	return 0;

}
