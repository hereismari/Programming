#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <utility>

#define MAX 26

using namespace std;

vector < vector<int> > pos(MAX);
string c1,c2;
int n1,n2;

void init(){
	for(int i = 0 ; i < MAX ; i++) pos[i].push_back(i);	
}

pair<int, int>  position(int x){
	for(int i = 0 ; i < pos.size() ; i++)
		for(int j = 0; j < pos[i].size() ; j++)
			if(pos[i][j] == x)
				return make_pair(i,j);

	return make_pair(0,0);
}

void put(int i, int j){
	pos[pos[i][j]].push_back(pos[i][j]);
	pos[i].erase(pos[i].begin() + j);	
}

void move_onto(pair<int, int> c, pair<int, int> d) {

    while(d.second + 1 != pos[d.first].size()) 
		put(d.first, d.second + 1);

    while(c.second + 1 != pos[c.first].size()) 
        put(c.first, c.second + 1);

    pos[c.first].erase(pos[c.first].begin() + c.second);
    pos[d.first].push_back(n1);
}
 
void move_over(pair<int, int> c, pair<int, int> d) {

    while(c.second + 1 != pos[c.first].size()) 
        put(c.first, c.second + 1);

    pos[c.first].erase(pos[c.first].begin() + c.second);
    pos[d.first].push_back(n1);
}
 
void pile_onto(pair<int, int> c, pair<int, int> d) {

    while(d.second + 1 != pos[d.first].size()) 
        put(d.first, d.second + 1);

    while(c.second != pos[c.first].size()) {
        pos[d.first].push_back(pos[c.first][c.second]);
        pos[c.first].erase(pos[c.first].begin() + c.second);
    }
}
 
void pile_over(pair<int, int> c, pair<int, int> d) {
    while(c.second != pos[c.first].size()) {
        pos[d.first].push_back(pos[c.first][c.second]);
        pos[c.first].erase(pos[c.first].begin() + c.second);
    }
}

void print(int x) {
	for(int i = 0; i < x; i++){
		printf("%d:",i);
		for(int j = 0 ; j < pos[i].size() ; j++)
			printf(" %d",pos[i][j]);
		printf("\n");
	}
}

int main(){
	int n;
	scanf("%d",&n);
	
	init();
	while(1){
		cin >> c1;
        if(c1 == "quit") break;
        cin >> n1 >> c2 >> n2;

        if(n1 == n2) continue;
        pair<int, int> c = position(n1);
        pair<int, int> d = position(n2);
        if(c.first == d.first) continue;
 
        if(c1 == "move" && c2 == "onto")
            move_onto(c, d);
        if(c1 == "move" && c2 == "over")
            move_over(c, d);
        if(c1 == "pile" && c2 == "onto")
            pile_onto(c, d);
        if(c1 == "pile" && c2 == "over")
            pile_over(c, d);
	
	}	

	print(n);
	return 0;
}
