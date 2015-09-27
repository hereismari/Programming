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
#define EPS 1e-7

using namespace std; 

int p, q, r, s, t, u;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double binSearch() {

    double i = 0.0, j = 1.0;

    while(i + EPS < j) {
        double m = (i+j)/2.0;
        if(f(i)*f(m) <= 0) j = m;
        else i = m;
    }

    return (i+j)/2.0;
}


int main() {
 
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
        if(f(0) * f(1) > 0) printf("No solution\n");
        else printf("%.4lf\n", binSearch());
    }

	return 0; 
}
