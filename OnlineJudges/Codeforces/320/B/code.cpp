#include <bits/stdc++.h>

#define F first
#define S second
#define pii pair<int,int>
#define pq priority_queue
#define mp make_pair
#define NO_ONE -1

using namespace std;

struct team {

    int m1, m2, w;
    team(int member1, int member2, int weight){
        m1 = member1;
        m2 = member2;
        w = weight;
    }

    bool operator < (team const &t) const{
        return w < t.w;
    }

};

int main() {

    int n, m, x;
    scanf("%d", &n);

    pq<team> p;
    int match[2*n];

    match[1] = NO_ONE;
    for(int i = 2; i <= 2*n; i++) {
        match[i] = NO_ONE;
        for(int j = 1; j < i; j++){
            scanf("%d",&x);
            p.push(team(j,i,x));
        }
    }

    while(!p.empty()){
        team top = p.top(); p.pop();
        if(match[top.m2] == NO_ONE && match[top.m1] == NO_ONE) {
               match[top.m1] = top.m2;
               match[top.m2] = top.m1;
        }
    }

    for(int i = 1; i <= 2*n; i++)
        printf("%d ",match[i]);

    return 0;
}

