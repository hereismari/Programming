#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,m,p,max_sum,median;
	scanf("%d %d %d %d %d",&n,&m,&p,&max_sum,&median);
	
	int sum = 0;
	int min_count = 0;
	int max_count = 0;
	int x;

	for(int i = 0 ; i < m; i++)
	{
		scanf("%d",&x);
		sum += x;
		
		if(x >= median) max_count++;
		else min_count++;			
	}
	
	int answer_max = 0;
	int answer_min = 0;
	
	if(min_count > (n-1)/2) { printf("-1"); return 0; }
	if(max_count >= (n+1)/2) { answer_min += n - m; sum += n -m;}
	else{
		while(max_count + answer_max < (n-1)/2 + 1) { answer_max++; sum += median; }
	
		for(int i = 0; i < n - m - answer_max; i++)
			{ answer_min++; sum++; }
	}

	if(sum > max_sum) { printf("-1"); return 0; } 
	for(int i = 0 ; i < answer_min; i++)
		printf("%d ",1);
	for(int i = 0 ; i < answer_max; i++)
		printf("%d ",median);

	return 0;
}
