#include <bits/stdc++.h>

using namespace std;

#define MAX 5500
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
#define pb push_back

int dp[MAX], bp[MAX];
vector<pair<pii, int> > v;
int main(){
    int n,w,h,x,y;
    memset(dp,-1,sizeof dp);
    memset(bp,-1,sizeof bp);
    cin>>n>>w>>h;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        v.pb(mp(mp(x,y),i+1));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(v[i].F.F>w&&v[i].F.S>h){ dp[i]=1;bp[i]=-1;}
        for(int j=0;j<i;j++){
            if(v[i].F.F>v[j].F.F&&v[i].F.S>v[j].F.S &&dp[j]+1>dp[i] && dp[j]!=-1){
                dp[i]=dp[j]+1;
                bp[i]=j;
            }
        }
    }
    int mx=-1,q=-1;
    for(int i=0;i<n;i++)
        if(dp[i]>mx){
            mx=dp[i];
            q=i;
        }
    stack<int> st;
    while(q!=-1){
        st.push(v[q].S);
        q=bp[q];
    }
    if(mx==-1)
        cout<<"0"<<endl;
    if(mx>0){
        cout<<mx<<endl;
        for(int i=0; i < mx-1; i++){
            int temp=st.top();
            st.pop();
            cout<<temp<<" ";
        }
        int temp=st.top();
            st.pop();
            cout<<temp<<endl;
    }
    return 0;
}
