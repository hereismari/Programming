#include <bits/stdc++.h> 

#define MAX 1000100 
#define EPS 1e-7
#define MOD 1000000007

#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

#define R 0
#define G 1
#define B 2

int n, m, x, y;

int main() {
 
    while(scanf("%d",&n) != EOF){

        string str;
        cin >> str;
        int counter[3];
        counter[0] = counter[1] = counter[2] = 0;
        bool b = false, g = false, r = false;
        for(int i = 0; i < n; i++) {
            if(str[i] == 'R') counter[R]++;
            if(str[i] == 'G') counter[G]++;
            if(str[i] == 'B') counter[B]++;
        }
    
        if(counter[R] && counter[G]) b = true;
        if(counter[B] && counter[R]) g = true;
        if(counter[G] && counter[B]) r = true;
        
        if(r && counter[G] > 1) b = true;
        if(b && counter[R] > 1) g = true;
        if(g && counter[B] > 1) r = true;
        
        if(counter[R] > 1 && g) b = true;
        if(counter[B] > 1 && r) g = true;
        if(counter[G] > 1 && b) r = true;
       
        if(b || (counter[B] && !counter[R] && !counter[G])) printf("B");
        if(g || (counter[G] && !counter[B] && !counter[R])) printf("G");
        if(r || (counter[R] && !counter[B] && !counter[G])) printf("R");
    }

	return 0; 
}
