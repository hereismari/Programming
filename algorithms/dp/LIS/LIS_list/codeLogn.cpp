#include <bits/stdc++.h>

using namespace std;

int main(){

	set<int> st;
	set<int>::iterator it;
	st.clear();
	
	int n;
	scanf("%d",&n);
	int a[n];

	for(int i = 0; i <n; i++)
		scanf("%d",&a[i]);
	
	for(int i=0; i<n; i++) {
		 if (s.insert(a[i]).second)
			{
			   it = st.find(a[i]);
			   k++;
			   if (k != st.end()) st.erase(k);
			}
	}
	cout<<st.size()<<endl;

	return 0;
}
