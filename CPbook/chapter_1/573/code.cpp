#include <bits/stdc++.h>

using namespace std;

int main() {
	
	while(true) {
		
		double h, u, d, f;
		
		cin >> h >> u >> d >> f;
		
		if(h == 0) break;
		
		int ans = 0;
		double fatigue = u * (f/100.0);
		double dist = 0;
		
		while(true) {
			
			//going up...
			dist += u;
			ans++;
			if(dist > h) {printf("success on day "); break;}
			
			//going down...
			dist -= d;
			if(dist < 0) {printf("failure on day "); break;}
			
			//updating u
			u -= fatigue;
			if(u < 0) u = 0;
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
