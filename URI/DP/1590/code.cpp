#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX 31
#define MAX2 100
 
using namespace std;
  
int t, n, k;
int cont,cont2;
int c;
int res;
 
int l[MAX2];
vector<int> tmp2;
vector<int> tmp1;
 
int main(){
  
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++)
    {
        scanf("%d %d",&n,&k);
        for(int j = 0; j < n; j++)
            scanf("%d",&l[j]);
         
        sort(l,l+n);        
		tmp1.clear();
		tmp2.clear();
		for(int j = 0; j < n; j++)
			tmp1.push_back(l[j]);

        res = 0;
        for(int p = MAX-1; p >= 0; p--){
            cont = 0;
            for(int j = tmp1.size()-1 ; j >= 0 ; --j){
//				printf("%d %d\n",int(tmp1[j]/pow(2,p)), int(pow(2,p)));
                if(int(tmp1[j] /  pow(2,p)) == 1){
                    cont++;
                    tmp2.push_back(tmp1[j]);
                }
            }

            if(cont>=k){
				
//				for(int j = 0; j < tmp1.size(); j++)
//					printf("%d ", tmp1[j]);
//				printf("\n");
//				for(int j = 0; j < tmp2.size(); j++)
//					printf("%d ", tmp2[j]);

                res = tmp2[0];
				tmp1.clear();
                for(int j = 1 ; j < tmp2.size(); j++)
                    res = res & tmp2[j];
				for(int j = 0 ; j < tmp2.size() ; j++)
					tmp1.push_back(tmp2[j]);
				tmp2.clear();
            }   
    }
	cont = 0;
	 for(int j = tmp1.size()-1 ; j >= 0 ; --j){
		//printf("%d %d\n",int(tmp1[j]/pow(2,p)), int(pow(2,p)));
          if(tmp1[j] % 2 == 1){
                 cont++;
                tmp2.push_back(tmp1[j]);
            }
    }


	 if(cont>=k){
				
//				for(int j = 0; j < tmp1.size(); j++)
//					printf("%d ", tmp1[j]);
//				printf("\n");
//				for(int j = 0; j < tmp2.size(); j++)
//					printf("%d ", tmp2[j]);

                res = tmp2[0];
				tmp1.clear();
                for(int j = 1 ; j < tmp2.size(); j++)
                    res = res & tmp2[j];
				for(int j = 0 ; j < tmp2.size() ; j++)
					tmp1.push_back(tmp2[j]);
				tmp2.clear();
            }   


    printf("%d\n",res);       
} 
    return 0;
}
