//KNAPSACK-PROBLEM 0/1
 
#include <stdio.h>
#include <string.h>
 
#define MAX_WEIGHT 101
#define MAX_ITEMS 101
#define WEIGHT 50
#define max(a,b) (a > b ? a : b)
 
using namespace std;
 
int w[MAX_ITEMS] = {0};
int v[MAX_ITEMS] = {0};
 
int num_items, weight, packed;
int m[MAX_ITEMS][MAX_WEIGHT] = {0};
 
//picked items
int picked[MAX_ITEMS][MAX_WEIGHT] = {0};
 
int n;

int knapsack(int n, int weight){

	for(int i = 0; i <= n ; i++){
		for(int c = 0 ; c <= weight; c++)
		{
			if(i == 0 || c == 0) m[i][c] = 0;
			else if(w[i] <= c){
				if(v[i] + m[i-1][c - w[i]] >= m[i-1][c])
				{
					m[i][c] = v[i] + m[i-1][c-w[i]];
					picked[i][c] = 1;
				}
				else{
					m[i][c] = m[i-1][c];
					picked[i][c] = -1;	
				}
			}
				 
			else{
				m[i][c] = m[i-1][c];
				picked[i][c] = -1;	
			}
		}
	}

	return m[n][weight];
}
 
void printPicks(int item, int size){
     
    while (item>=0){
        if (picked[item][size]==1){
            packed++;
            weight += w[item];
            size -= w[item];
            item--;
        }
        else{
            item--;
        }
    }
}
 
int main() {
 
    scanf("%d",&n);
    for(int j = 0; j < n ; j++){
         
        scanf("%d",&num_items);
        for(int i = 1; i <= num_items ; i++)
            scanf("%d %d",&v[i],&w[i]);
     
        packed = 0;
        weight = 0;
        memset(m, 0, sizeof(m[0][0]) * MAX_WEIGHT * MAX_WEIGHT);
        memset(picked, 0, sizeof(picked[0][0]) * MAX_WEIGHT * MAX_WEIGHT);
         
        printf("%d brinquedos\n",knapsack(num_items,WEIGHT));
        printPicks(num_items,WEIGHT);
        printf("Peso: %d kg\n", weight);
        printf("sobra(m) %d pacote(s)\n\n", num_items - packed); 
    }
 
    return 0;
}
