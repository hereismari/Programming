nclude <bits/stdc++.h>
#define MAX 5000010

using namespace std;

int t,a,b;
int ans[MAX];

void pre(){
    
    memset(ans,0,sizeof(ans));
    
    for(int i = 2; i < MAX;i++){
        if(!ans[i])
            for(int j=1;i*j<MAX;j++){
                for(int k=i*j;k%i==0;k/=i){
                      ans[i*j]++;
            }
        }
        ans[i]+=ans[i-1];
    }
}

int main()
{
    pre();
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%d\n",ans[a]-ans[b]);
    }
    return 0;
}
