#include <stdio.h>
#include <string.h>
#define MAX 100
using namespace std;

int t;
int n;
char s[MAX];
char entrada[MAX];

void sort(int n){
	int tmp;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n-i -1 ; j++)
			if(s[j] - 'A' >= s[j+1] - 'A'){
				tmp = s[j];
				s[j] = s[j+1];
				s[j+1] = tmp;	
			} 
}
int main(){

	scanf("%d",&t);
	for(int i = 0 ; i < t ; i++)
	{
		scanf("%d",&n);
		scanf("%s",s);
		
		int minor_index = 0;
		int k =0;
		while(k == minor_index && k < n){
			for(int j = k; j < n; j++)
				if(s[j] - 'A' < s[minor_index] -'A')
					minor_index = j;
			if(minor_index == k)
			{
				minor_index++;
				k++;
			}
		}		

		int tmp = s[minor_index];
		for(int j = minor_index; j >= k +1;j--)
			s[j] = s[j-1];
			
		s[k] = tmp;
		printf("%s\n",s);
	}




	return 0;
}
