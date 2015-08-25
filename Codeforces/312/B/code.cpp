#include <bits/stdc++.h>
#define MAX 10000010

using namespace std;

struct aux{
	int begin,end, count;
	aux(int begin=INT_MAX, int end=0, int count=0){
		this->begin = begin;
		this->end = end;
		this->count = count;
	}
	void setBegin(int b){
		begin = min(begin,b);
	}
	void setEnd(int e) {
		end = max(end,e);
	}	
};

bool comp(aux a, aux b){
	if(a.count != b.count) return a.count > b.count;
	return abs(a.end - a.begin) < abs(b.end - b.begin);
}

aux x[MAX];
int n,a;

int main() {

	scanf("%d",&n);
	int answerC, answerB, answerE;
	answerC = answerE = 0;
	answerB = INT_MAX;
	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		x[a].setBegin(i);
		x[a].setEnd(i);
		x[a].count++;
		
		if(x[a].count > answerC){
			answerC = x[a].count;
			answerB = x[a].begin;
			answerE = x[a].end;
		}
		
		else if(x[a].count == answerC){
			if(abs(x[a].end - x[a].begin) < abs(answerE - answerB)){
				answerB = x[a].begin;
				answerE = x[a].end;		
			}
		}
		
		
	}

	printf("%d %d\n",answerB + 1, answerE + 1);	
	return 0;
}
