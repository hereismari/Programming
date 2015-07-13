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
		it = st.lower_bound(a[i]);
		if (it != st.end()) st.erase(it);
		st.insert(a[i]);
	}
	cout<<st.size()<<endl;

	return 0;
}
