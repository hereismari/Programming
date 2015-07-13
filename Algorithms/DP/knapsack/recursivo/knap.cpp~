#include <stdio.h>
#define max(a,b) (a > b ? a : b)

int matrix[100][100] = {0};
int picks[100][100] = {0};

int knapsack(int index, int size, int weights[],int values[]){
    int take,dontTake;

    take = dontTake = 0;

    if (matrix[index][size]!=0)
        return matrix[index][size];

    if (index==0){
        if (weights[0]<=size){
            picks[index][size]=1;
            matrix[index][size] = values[0];
            return values[0];
        }
        else{
            picks[index][size]=-1;
            matrix[index][size] = 0;
            return 0;
        }
    }

    if (weights[index]<=size)
        take = values[index] + knapsack(index-1, size-weights[index], weights, values);

    dontTake = knapsack(index-1, size, weights, values);

    matrix[index][size] = max (take, dontTake);

    if (take>dontTake)
        picks[index][size]=1;
    else
        picks[index][size]=-1;

    return matrix[index][size];

}

void printPicks(int item, int size, int weights[]){

    while (item>=0){
        if (picks[item][size]==1){
            printf("%d ",item);
            item--;
            size -= weights[item];
        }
        else{
            item--;
        }
    }

    printf("n");

return;
}

int main(){
    int nItems = 4;
    int knapsackSize = 10;
    int weights[4] = {5,4,6,3};
    int values[4] = {10,40,30,50};

    printf("Max value = %dnn",knapsack(nItems-1,knapsackSize,weights,values));

    printf("Picks were: ");
    printPicks(nItems-1,knapsackSize, weights);

    return 0;
}
