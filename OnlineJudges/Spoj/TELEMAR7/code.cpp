#include <bits/stdc++.h>

using namespace std;

struct data{

	int id;
	int value;
	int freq;

	data(int id, int value, int freq){
		this->id = id;
		this->value = value;
		this->freq = freq;
	}

};

bool operator <(const data &a, const data &b){

	if(a.value == b.value) return a.id > b.id;
	return a.value > b.value;

}

priority_queue<data> q;

int main(){

	int n;
	int k;
	int x;
	scanf("%d %d",&n,&k);
	for(int i = 0 ; i < n; i++) 
		q.push(data(i,0,0));
	
	for(int i = 0 ; i < k; i++){
		
		scanf("%d",&x);
		data v = q.top(); q.pop();
		q.push(data(v.id,v.value + x, v.freq + 1));

	}

	for(int i = 0; i < n ; i++){
		printf("%d %d\n",i+1,q.top().freq);
		q.pop();
	}

	return 0;
}
