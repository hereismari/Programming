#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >

using namespace std; 


int main() {

    int t,s,q;
    scanf("%d %d %d",&t,&s,&q);
    int ans = 0;
    while(s < t){
        s = s*q;
        ans++;
    }

    printf("%d",ans);
    return 0;
}
