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
int matrix[MAX_ITEMS][MAX_WEIGHT] = {0};
 
//picked items
int picked[MAX_ITEMS][MAX_WEIGHT] = {0};
 
int n;
 
int knapsack(int index, int size) {
 
    int take,dontTake;
    take = dontTake = 0;
 
    //DP
    if (matrix[index][size] != 0)
        return matrix[index][size];
     
    if (index==0){
        if (w[0]<=size){
            picked[index][size] = 1;
            matrix[index][size] = v[0];
            return v[0];
        }
        else{
            picked[index][size] = -1;
            matrix[index][size] = 0;
            return 0;
        }
    }
 
    if (w[index] <= size)
        take = v[index] + knapsack(index-1, size-w[index]);
     
    dontTake = knapsack(index-1, size);
     
    matrix[index][size] = max(take, dontTake);
     
    if (take > dontTake)
        picked[index][size] = 1;
    else
        picked[index][size] = -1;
 
    return matrix[index][size];
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
        for(int i = 0; i < num_items ; i++)
            scanf("%d %d",&v[i],&w[i]);
     
        packed = 0;
        weight = 0;
        memset(matrix, 0, sizeof(matrix[0][0]) * MAX_WEIGHT * MAX_WEIGHT);
        memset(picked, 0, sizeof(picked[0][0]) * MAX_WEIGHT * MAX_WEIGHT);
         
        printf("%d brinquedos\n",knapsack(num_items-1,WEIGHT));
        printPicks(num_items-1,WEIGHT);
        printf("Peso: %d kg\n", weight);
        printf("sobra(m) %d pacote(s)\n\n", num_items - packed); 
    }
 
    return 0;
}
