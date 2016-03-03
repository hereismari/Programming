//KNAPSACK-PROBLEM 0/1
#include <bits/stdc++.h>
 
#define MAX_WEIGHT 10000
#define MAX_ITEMS 10000
#define MAX 10000
#define WEIGHT 50
#define FLAG -1
#define max(a,b) (a > b ? a : b)
 
using namespace std;
 
int w[MAX_ITEMS];
int v[MAX_ITEMS];
 
int num_items, weight, packed;
int matrix[MAX_ITEMS][MAX];
 
int n,capacidade;
 
int knapsack(int index, int size) {
 
    int take,dontTake;
    take = dontTake = 0;
 
    //DP
    if (matrix[index][size] != FLAG)
        return matrix[index][size];
     
    if (index==0){
        if (w[0]<=size){
            matrix[index][size] = v[0];
            return v[0];
        }
        else{
            matrix[index][size] = 0;
            return 0;
        }
    }
 
    if (w[index] <= size)
        take = v[index] + knapsack(index-1, size-w[index]);
     
    dontTake = knapsack(index-1, size);
     
    matrix[index][size] = max(take, dontTake);
 
    return matrix[index][size];
}

int main() {
	
	int count = 1;
  
         
        scanf("%d %d",&capacidade,&num_items);
        //if(num_items == 0 && capacidade == 0) break;
        for(int i = 0; i < num_items ; i++)
            scanf("%d %d",&w[i],&v[i]);
     
        packed = 0;
        weight = 0;
        memset(matrix, FLAG, sizeof(matrix));
         
        //printf("Teste %d\n",count++);
        printf("%d\n",knapsack(num_items-1,capacidade));
    
 
    return 0;
}
