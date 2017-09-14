#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-12;

struct PT {
	double x, y;
	PT(){}
	PT(double x, double y) : x(x), y(y) {}
	PT operator - (const PT &p) const {return PT(x-p.x, y-p.y);}
};

double cross(PT p, PT q) {
	return p.x*q.y-p.y*q.x;
}

double dot(PT p, PT q) {
	return p.x*q.x+p.y*q.y;
}

double dist2(PT p, PT q) {
	return dot(p-q,p-q);
}

bool lines_parallel(PT a, PT b, PT c, PT d) {
	return fabs(cross(b-a, c-d)) < EPS;
}

bool lines_collinear(PT a, PT b, PT c, PT d) {
	return lines_parallel(a, b, c,  d) && fabs(cross(a-b,a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}

bool segment_intersects(PT a, PT b, PT c, PT d) {
	if (lines_collinear(a, b, c, d)) {
		if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
		if (dot(c - a, c - b) > 0 && dot (d- a, d - b) > 0 && dot(c - b, d - b) > 0) {
			return false;
		}
		return true;
	}
	
	if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
	if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
	return true;
}

int dp[110];
vector<PT>points;
PT pa, pb;
int pd(int i, int n) {
	if(dp[i] != -1) return dp[i];
	
	int mx = 0;
	for(int j = 0; j < n; j++) {
		if(!segment_intersects(pa, points[i], points[j], pb) &&
		 !segment_intersects(pa, points[j], points[i], pb) &&
		 points[i].y > points[j].y) {
			 mx = max(mx, pd(j, n));
		 }
	}
	
	dp[i] = mx+1;
	return dp[i];
	
}

/**
 4 1 10
 2 4
 5 1
 6 5
 7 8
 
 */
int main() {
	int n;
	double xa, xb;
	
	for(int i = 0; i < 110; i++)dp[i] = -1;
	
	scanf(" %d", &n);
	scanf(" %lf %lf", &xa, &xb);
	
	pa = PT(xa, 0);
	pb  = PT(xb, 0);
	
	for(int i = 0; i < n; i++) {
		double x, y;
		scanf(" %lf %lf", &x, &y);
		PT p = PT(x, y);
		points.push_back(p);
	}
	
	int mx = 0;
	for(int i = 0; i < n; i++) {
		mx = max(mx, pd(i, n));
	}
	
	printf("%d\n", mx);
	
	return 0;
}



