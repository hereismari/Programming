#include <stdio.h>
#define MAX 100

using namespace std;

int seg_tree[4*MAX];
int array[MAX];

void build(int id, int begin, int end){
	
	if(begin == end) { seg_tree[id] = id; return;}
	
	int middle = (begin + end)/2;
	build(2*id,begin,middle);
	build(2*id + 1,middle+1,end);
	
	seg_tree[id] = seg_tree[2*id] + seg_tree[2*id + 1];
}

void update(int id, int begin, int end, int val, int pos){

	if(begin == end) { seg_tree[id] = val; return;}
	
	int middle = (begin + end)/2;
	if(pos <= middle) update(2*id,begin,middle,val,pos);
	else update(2*id + 1,middle+1,end,val,pos);
	
	seg_tree[id] = seg_tree[2*id] + seg_tree[2*id + 1];
}

int getSum(int id, int begin, int end, int begin_sum, int end_sum){

	if(end_sum < begin || begin_sum > end) return 0;
	if(begin >= begin_sum && end <= end_sum) return seg_tree[id];

	int middle = (begin + end)/2;
	return getSum(2*id,begin,middle,begin_sum,end_sum) + getSum(2*id+1,middle+1,end,begin_sum,end_sum);

}

int main(){




	return 0;
}

