#include <bits/stdc++.h>
#define MAX 100

using namespace std;

typedef pair < int , int > PI;

int A[MAX], N;
int pre[MAX];
vector<int> res;

void LIS() {

    memset(pre,-1,sizeof pre);

	map<int,int> m;
    map<int,int>::iterator k,l;

	int j = -1;
    for (int i = 0; i < N; i++) {
        if (m.insert(PI(A[i],i)).second) //se i != 0 
		{
           k = m.find(A[i]); 
           l = k;
           k++;
           if (l == m.begin()) //se for primeiro elemento nao tem pai
                pre[i] = -1;
           else {
               l--;
               pre[i] = l->second;
           }
           if (k != m.end())
              m.erase(k);
        }
    }

    k = m.end();
    k--;
    j = k->second;
    while (j != -1)
    {
          res.push_back(A[j]);
          j = pre[j];
    }

    reverse(res.begin(),res.end());
}

int main(){

	set<int> st;
	set<int>::iterator it;
	st.clear();
	
    string s;
    cin >> s;

    int n = s.size();
	for(int i = 0; i < n; i++)
		A[i] = s[i] - 'A';
	

	LIS();
	printf("%d\n",res.size());
	return 0;
}

