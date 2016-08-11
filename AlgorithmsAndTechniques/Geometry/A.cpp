#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define S second
#define F first

using namespace std;

struct PT {
	
	ll x,y ;
	PT() {}
	PT(ll x, ll y) : x(x) , y(y) {}
	PT(const PT &p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
	PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
	PT operator * (ll c) const { return PT(x * c, y * c); }
	PT operator / (ll c) const { return PT(x / c, y / c); }
	
};

ll dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
ll dist(PT p, PT q) { return dot(p-q,p-q); }
ll cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }

PT min(PT p, PT q) {
	if(p.x < q.x or p.x == q.x and p.y < q.y) return p;
	return q;
} 

PT max(PT p, PT q) {
	if(p.x > q.x or p.x == q.x and p.y > q.y) return p;
	return q;
}

struct R {
	
	ll a, b, c;
	PT A, B;	
	R(PT p, PT q) { 
		a = q.y - p.y; 
		b = p.x - q.x; 
		c = -a*p.x - b*p.y;
		A = p, B = q;
	}

	bool segmentIntersect(R r) {
		if(max(r.A.x, r.B.x) < min(A.x, B.x) || max(A.x, B.x) < min(r.A.x, r.B.x) || max(r.A.y, r.B.y) < min(A.y, B.y) || max(A.y, B.y) < min(r.A.y, r.B.y))
			return false;
		return (cross(r.B-A, B-A) * cross(B-A, r.A-A) >= 0 && 
			cross(B-r.A, r.B-r.A) * cross(r.B-r.A, A-r.B) >= 0);
	}

};

/*PT ProjectPointSegment(PT a, PT b, PT c) {
	int r = dot(b-a, b-a);
	if (fabs(r) < EPS) return a;
	r = dot(c-a, b-a)/r;
	if (r < 0) return a;
	if (r > 1) return b;
	return a + (b-a)*r;
}

int distancePointSegment(PT a, PT b, PT c) {
	return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
*/

bool isCollinear(R lhs, R rhs, bool debug=false) {
	return lhs.a*rhs.A.x + lhs.b*rhs.A.y + lhs.c == 0 && 
		lhs.a*rhs.B.x + lhs.b*rhs.B.y + lhs.c == 0;
}

bool between(ll a, ll b, ll p) {
	return (p >= a && p <= b) || (p >= b && p <= a); 
}

bool isSegmentCollinear(R lhs, R rhs) {
	if(!isCollinear(lhs,rhs)) return false;
	return between(lhs.A.x, lhs.B.x, rhs.A.x) && between(lhs.A.y, lhs.B.y, rhs.A.y) ||
		between(lhs.A.x, lhs.B.x, rhs.B.x) && between(lhs.A.y, lhs.B.y, rhs.B.y) || 
		between(rhs.A.x, rhs.B.x, lhs.A.x) && between(rhs.A.y, rhs.B.y, lhs.A.y) ||
		between(rhs.A.x, rhs.B.x, lhs.B.x) && between(rhs.A.y, rhs.B.y, lhs.B.y);
}

pair<double, double> findPoint(R lhs, R rhs) {
	double x, y;
	double det = lhs.a*rhs.b - rhs.a*lhs.b;
	x = (rhs.b*-1*lhs.c + lhs.b*rhs.c)/det;
	y = (lhs.a*-1*rhs.c + rhs.a*lhs.c)/det;	
	return make_pair(x, y);
}

bool notIntersect(R lhs, R mhs, R rhs) {
	pair<double, double> p = findPoint(lhs,rhs);
	return mhs.a * p.F + mhs.b * p.S + mhs.c != 0;
}

R segment(R lhs, R rhs) {
	
	PT p, q;
	
	p =  min(min(lhs.A, lhs.B), min(rhs.A, rhs.B));
	q =  max(max(lhs.A, lhs.B), max(rhs.A, rhs.B));
	
	return R(p,q);
}

 int main() {
	 
	 freopen("guards.in", "r", stdin);
	 freopen("guards.out", "w", stdout);
	 
	 int n;
	 scanf("%d", &n);
	 
	 
	 vector<R> v;
	 vector<int> valid;
	 ll x1, y1, x2, y2;
	 
	 for(int i = 0; i < n; i++){
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		PT p = PT(x1,y1);
		PT q = PT(x2, y2);
		R r = R(p,q);
		v.pb(r);
		valid.pb(true);
	}
	
	
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++){
			if(valid[i] && valid[j] && isSegmentCollinear(v[i], v[j])){
				valid[i] = valid[j] = false;
				v.pb(segment(v[i], v[j]));
				valid.pb(true);
				n++;
			}
		}

	ll ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			for(int k = j+1; k < n; k++)
				if(valid[i] && valid[j] && valid[k])
					if(v[i].segmentIntersect(v[j]) && v[i].segmentIntersect(v[k]) && v[j].segmentIntersect(v[k]))
					{
						
						ans += notIntersect(v[i],v[j],v[k]);
						//printf("%d %d %d\n", i, j, k);
					}
				
	printf("%lld\n", ans);
	return 0;
 }
