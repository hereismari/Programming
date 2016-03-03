#include<bits/stdc++.h>
#define sz 32
using namespace std;

char mat[sz][sz][sz];
int cost[sz][sz][sz];
int color[sz][sz][sz];
queue<int>Q;
int Z[6]={-1,0,0,0,0,1};
int X[6]={0,1,0,-1,0,0};
int Y[6]={0,0,1,0,-1,0};

int main()
{
    int L,R,C,i,j,k,a,b,c,d,e,f,ua,ub,uc,va,vb,vc;
    while(scanf("%d%d%d",&L,&R,&C)&&L&&R&&C)
    {
        getchar();
        for(k=0;k<L;k++)
        {
            for(i=0;i<R;i++)
            {
                for(j=0;j<C;j++)
                {
                    scanf("%c",&mat[k][i][j]);
                    if(mat[k][i][j]=='S')
                    {
                        c=k;
                        a=i;
                        b=j;
                    }
                    if(mat[k][i][j]=='E')
                    {
                        mat[k][i][j]='.';
                        f=k;
                        d=i;
                        e=j;
                    }
                }
                getchar();
            }
            getchar();
        }

        Q.push(c);
        Q.push(a);
        Q.push(b);

        color[c][a][b]=1;

        while(!Q.empty())
        {
            uc = Q.front();
            Q.pop();

            ua = Q.front();
            Q.pop();

            ub = Q.front();
            Q.pop();

            for(i=0; i<6; i++)
            {
                vc = uc+Z[i];
                va = ua+X[i];
                vb = ub+Y[i];

                if((va>=0&&va<R) && (vb>=0&&vb<C)&& (vc>=0 && vc<L)&& mat[vc][va][vb]=='.')
                {
                    if(color[vc][va][vb]==0)
                    {
                        color[vc][va][vb]=1;
                        Q.push(vc);
                        Q.push(va);
                        Q.push(vb);
                        cost[vc][va][vb]=cost[uc][ua][ub]+1;
                    }
                }
            }
        }
        if(cost[f][d][e]==0)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n",cost[f][d][e]);
        }

        memset(color,0,sizeof(color));
        memset(cost,0,sizeof(cost));
    }
    return 0;
}
