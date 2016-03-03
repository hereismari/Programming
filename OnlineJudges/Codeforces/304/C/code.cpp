#include <bits/stdc++.h> 
#define MAX 2*3628810
using namespace std;

int main(){

	int x;	
	int n;
	scanf("%d",&n);

	int k1;
	scanf("%d",&k1);
	queue<int> q1;
	for(int i = 0 ; i < k1; i++){
		scanf("%d",&x);
		q1.push(x);
	}

	int k2;
	scanf("%d",&k2);
	queue<int> q2;
	for(int i = 0 ; i < k2; i++){
		scanf("%d",&x);
		q2.push(x);
	}

	int j = 0;
	while(j < MAX){

		if(q1.empty()) { printf("%d %d\n",j,2); return 0;}
		if(q2.empty()) { printf("%d %d\n",j,1); return 0;}

		int card2 = q2.front();
		int card1 = q1.front();
		if(card1 > card2){
			q1.pop();
			q2.pop();
			q1.push(card2);
			q1.push(card1);
		}
		else{
			q1.pop();
			q2.pop();
			q2.push(card1);
			q2.push(card2);
		}

		j++;
	}

	printf("-1");
	return  0;
}
