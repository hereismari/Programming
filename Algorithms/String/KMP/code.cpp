#include <bits/stdc++.h> 

#define MAX 1001001 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int reset[MAX];
void preprocess(char t[]){

	int j = -1;
	memset(reset,0, sizeof reset);
	reset[0] = -1;

    for (int i = 1; i < strlen(t); i++) {

        j = reset[i - 1];
        while (j >= 0) {
            if (t[j] == t[i - 1])
                break;
            else
                j = reset[j];
        }
        reset[i] = j + 1;
	}

//	for(int i = 0; i < strlen(t); i++)
//		printf("%d ",reset[i]); 
}

int main() {
 
	int n;
	char c;
	while(scanf("\n%d\n",&n) != EOF){
		char t[n];
		scanf("%s\n",t);
		preprocess(t);
		int i = 0, j = 0; bool flag = true;
		while ((c = getchar()) != '\n'){
		//	printf("%c",c);
			while(true) {
				if(j == -1){
					j = 0; break;
				}
				else if(c == t[j]){
					j++;
					if(j == n) {j = reset[n]; printf("%d\n",i-n);}
					break;
				}
				else
					j = reset[j];
			}
			i++;
		}
		printf("\n");
	}

	return 0; 
}
