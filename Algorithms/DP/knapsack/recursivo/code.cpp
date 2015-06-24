//KNAPSACK-PROBLEM 0/1

#include <stdio.h>
#define MAX_WEIGHT 101
#define MAX_ITEMS 101

#define max(a,b) (a > b ? a : b)

using namespace std;

int w[MAX_ITEMS] = {0};
int v[MAX_ITEMS] = {0};

int num_items, weight;

int matrix[MAX_ITEMS][MAX_WEIGHT] = {0};

//picked items
int picked[MAX_ITEMS][MAX_WEIGHT] = {0};

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
    
	if (take > dontTake)
		picked[index][size] = 1;
	else
		picked[index][size] = -1;

    return matrix[index][size] = max(take,dontTake);
}

void printPicks(int item, int size){
	
    while (item >= 0 && size > 0){
		if (picked[item][size] == 1){
            printf("%d ",item);	
            size -= w[item];
		    item--;
        }
        else{
            item--;
        }
    }
}
int main(){
	
	scanf("%d %d",&num_items, &weight);

	for(int i = 0; i < num_items ; i++)
		scanf("%d",&v[i]);

	for(int i = 0; i < num_items ; i++)
		scanf("%d",&w[i]);

	printf("%d\n",knapsack(num_items,weight));
	printPicks(num_items-1,weight);

	return 0;
}

