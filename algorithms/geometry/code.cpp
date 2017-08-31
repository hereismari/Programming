#include <bits/stdc++.h> 

#define MAX 1001
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

struct P {

	int x,y;
	P(int a=0, int b=0) { x = a; y = b; }
	
    int operator * (const P &a) const { return x*a.x + y*a.y; }
    int operator ^ (const P & a) const { return x^a.y - y^a.x;}
	P operator - (const P & a) const { return P(x-a.x, y - a.y);}
	bool operator < (const P & a) const { return x < a.x || (x == a.x && y < a.y); }
	int ccw(P a, P b) { return (a - (*this)) ^ (b - (*this)); }
	// if ccw > 0, left turn. else right turn(this->A->b)
};

struct V {
    P A, B;
    ll a, b, c;
    V(P A, P B) { this.A = A; this.B = B; a = B.y - A.y; b = A.x - B.x; c = -a*A.x -b*B.y;}
    bool segmentIntersect(R r) {
	if(max(r.A.x, r.B.x) < min(A.x, B.x) || max(A.x, B.x) < min(r.A.x, r.B.x) || max(r.A.y, r.B.y) < min(A.y, B.y) || max(A.y, B.y) < min(r.A.y, r.B.y)) return false;
	return (cross(r.B-A, B-A) * cross(B-A, r.A-A) >= 0 && cross(B-r.A, r.B-r.A) * cross(r.B-r.A, A-r.B) >= 0);
	}
};

double distPointPoint(P A, P B) { return sqrt((A.x - B.x)*(A.x - B-x) + (A.y - B.y)*(A.y-B.y)); }

double distLinePoint(V a, P C) {
    double dist = ((V.B - V.A)^(C-V.A)) / sqrt((V.B-V.A)*(V.B-V.A));
    if(isSegment) {
        int dist1 = ((C - V.A)*(V.A-V.B));
        if (dist1 > 0) return distPointPoint(V.A, C);
        int dist2 = ((V.A - V.B)*(V.B-C));
        if (dist2 > 0) return distPointPoint(V.B, C);
    }
    return abs(dist);
}

pair<double, double> findPoint(R lhs, R rhs) {
	double x, y;
	double det = lhs.a*rhs.b - rhs.a*lhs.b;
	x = (rhs.b*-1*lhs.c + lhs.b*rhs.c)/det;
	y = (lhs.a*-1*rhs.c + rhs.a*lhs.c)/det;	
	return make_pair(x, y);
}

pair<double, double> findPoint(V lhs, V rhs) {
        double x, y;    
        if(lhs.a != 0) {
            y = (rhs.a*lhs.c - lhs.a*rhs.c)/(1.0*(lhs.a*rhs.b - lhs.b*rhs.a));
            x = (-lhs.c - lhs.b*y)/(1.0*lhs.a);
        }
        else {
            x = (rhs.b*lhs.c - lhs.b*rhs.c)/(1.0*(rhs.a*lhs.b - lhs.a*rhs.b));
            y = (-lhs.c - lhs.a*x)/(1.0*lhs.b);
        }
       return mp(x, y);
}

int areaPolygon(vector<P> pol){

    int area = 0;
    int n = pol.size();
    for(int i = 0; i < n-1; i++){
        P p1 = P(pol[i].x - pol[0].x, pol[i].y - pol[0].y);
        P p2 = P(pol[i+1].x - pol[0].x, pol[i+1].y - pol[0].y);
        area += p1 ^ p2;
    }
    return area;
}


vector<P> convex_hull(vector<P> p) {

	int n = p.size(), k = 0;
	vector<P> H(2*n);

	// Sort points lexicographically
	sort(p.begin(), p.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && ((H[k-1] - H[k-2]) ^ (P[i] - H[k-1])) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && ((H[k-1] - H[k-2]) ^ (P[i] - H[k-1])) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}


P p[MAX];
int maxV, n, v[MAX][MAX], t;

int main() { return 0; }
