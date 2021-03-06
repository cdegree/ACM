#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);
const int N = 100;
struct Point {
	double x, y;
	Point() { };
	Point(double x, double y) : x(x), y(y) { }
};

inline double sqr(double x) { return x * x; }

void gao(const Point& u, const Point& v, double r, vector<Point>& ret) {
	double a = sqr(v.x - u.x) + sqr(v.y - u.y);
	double b = 2 * ((v.x - u.x) * u.x + (v.y - u.y) * u.y);
	double c = sqr(u.x) + sqr(u.y) - r * r;
	// printf("%lf %lf %lf\n", a, b, c);
	double d = b * b - 4 * a * c;
	ret.push_back(u);
	if (d < 0) {
		return;
	}
	d = sqrt(d);
	double t1 = (-b + d) / (2 * a);
	double t2 = (-b - d) / (2 * a);
	if (t1 > t2) {
		swap(t1, t2);
	}
	// printf("(%.3lf, %.3lf)\n", t1, t2);
	if (t1 > EPS && t1 < 1 - EPS) {
		ret.push_back(Point(u.x + (v.x - u.x) * t1, u.y + (v.y - u.y) * t1));
	}
	if (t2 > EPS && t2 < 1 - EPS && t2 - t1 > EPS) {
		ret.push_back(Point(u.x + (v.x - u.x) * t2, u.y + (v.y - u.y) * t2));
	}
}

double tri(const Point& u, const Point& v) {
	return u.x * v.y - u.y * v.x;
}

double arc(const Point& u, const Point& v, double r) {
	double t = atan2(v.y, v.x) - atan2(u.y, u.x);
	while (t > PI) {	// WA!!
		t -= 2 * PI;
	}
	while (t < -PI) {
		t += 2 * PI;
	}
	return r * r * t;
}

double area(vector<Point> v,double r)
{
	double ret = 0 ;
	for (int i = 1; i < (int)v.size(); ++i) {
		// printf("%.3lf %.3lf: %.4lf\n", v[i].x, v[i].y, ret);
		if (hypot((v[i - 1].x + v[i].x) / 2, (v[i - 1].y + v[i].y) / 2) < r) {
			ret += tri(v[i - 1], v[i]);
		} else {
			ret += arc(v[i - 1], v[i], r);
		}
	}
	return ret;
}
Point P[N];
int main() {
	bool blank = false;
	double x, y, r, x1, y1, x2, y2, ans;
	int T=0;
	int n=5;
	while (~scanf("%lf%lf%lf", &x, &y, &r)) {
		for(int i=0;i<n;++i){
			scanf("%lf %lf",&P[i].x,&P[i].y);
			P[i].x-=x;
			P[i].y-=y;
		}
		if (T++) {
			puts("");
		}

		vector<Point> v;
		for(int i=0;i<n;++i)
		{
			gao(P[i],P[(i+1)%n],r,v);
		}
		/*
		gao(Point(x1, y1), Point(x1, y2), r, v);
		gao(Point(x1, y2), Point(x2, y2), r, v);
		gao(Point(x2, y2), Point(x2, y1), r, v);
		gao(Point(x2, y1), Point(x1, y1), r, v);
		gao(Point(x2, y1), Point(x1, y1), r, v);
		*/
		ans = 0;

		v.push_back(v.front());

		ans = area(v,r);

		printf("%.10lf\n", fabs(ans) / 2);
	}

	return 0;
}
