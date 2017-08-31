#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n, m, x, y;

bool ans[MAX];

void precalculate() {

    memset(ans, false, sizeof ans);

    int big_pointer = 0, small_pointer = 0;
    int counter = 0;
    while(big_pointer <= 180) {
        ans[min(abs(small_pointer-big_pointer), abs((360-small_pointer)-big_pointer))] = true;
        small_pointer += 6;
        if(counter % 12 == 0) big_pointer += 6;
        counter++;
    }

}

int main() {

    precalculate();

    while(scanf("%d",&n) != EOF){
        printf("%c\n", ans[n] ? 'Y' : 'N');
    }

	return 0; 
}
