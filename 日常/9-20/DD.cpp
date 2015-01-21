#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#define X first
#define Y second
#define sqr(x) (x)*(x)
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}
#define eps 1e-8
const double pi = acos(-1);
int l[1002][1002]; int ll[1002][1002]; double jiao[1002][1002];
int equal(double a, double b) {if(fabs(a - b) <= eps)return 1; else return 0;}
struct point {int x; int y; int id;};
struct npoint {int x; int y; int id;};
struct point p[1002], ss; struct ff {struct point p[1002];};
struct ff s[1002]; int T, n, m;
int cross(struct npoint a, struct npoint b, struct npoint c) {return((double)(b.x - c.x) * (a.y - c.y) - (double)(a.x - c.x) * (b.y - c.y)) > 0 ? 1 : -1;}
double get(struct point x, struct point s) {if(equal(jiao[x.id][s.id], 0.0)) {double ans = atan2(x.y - s.y, x.x - s.x); if(ans < 0) ans += pi + pi; jiao[x.id][s.id] = ans; return jiao[x.id][s.id];} else return jiao[x.id][s.id];}
int cmp(const void*a, const void*b) {struct point*x, *y; x = (struct point*)a; y = (struct point*)b; if(x->x == ss.x && x->y == ss.y)return -1; if(y->x == ss.x && y->y == ss.y)return 1; double ans1 = get(*x, ss); double ans2 = get(*y, ss); return ans1 - ans2 >= 0 ? 1 : -1;}
int cmp2(const void*a, const void*b) {struct point*x, *y; x = (struct point*)a; y = (struct point*)b; int t = x->x - y->x; if(t == 0) t = x->y - y->y; return t;}
int nbinsareh(struct point*a, struct point x, struct point s) //二分查找与a
{double key = get(x, s); key = key + pi; if(key >= 2 * pi) key -= pi + pi; int low, high, mid; low = 1; high = n - 1; double a1 = get(a[low], s); double a2 = get(a[high], s); if(a1 - key > 0)return 0; if(a2 - key < 0)return n - 1; while(low + 1 != high) { mid = (low + high) / 2; a1 = get(a[mid], s); if(a1 - key >= 0) high = mid; else low = mid;} return low;}
int lfind(int a, int b, int x) //找编号为a，b的两点构成线段的左右分布情况 x==0 逆时针方向，否则返回顺时针方向
{int ans; if(ll[a][b] == 0) {struct point*now; now = s[a].p; int start = l[p[a].id][p[b].id]; int end = nbinsareh(now, p[b], p[a]); if((p[b].y - p[a].y) < 0) { ans = end + n - 1 - start;} else ans = end - start; ll[a][b] = ans;} else { ans = ll[a][b];} if(x == 0)return ans; else return n - 2 - ans;}
int rfind(int a, int b, int c) //a作为原点 b到c逆时针三角区域点数
{struct point*now; now = s[a].p; int start = l[p[a].id][p[b].id]; int end = l[p[a].id][p[c].id]; int ans; if((p[c].y - p[a].y) >= 0 && (p[b].y - p[a].y) < 0) { ans = end - 1 + n - 1 - start;} else { ans = end - 1 - start;} return ans;}
int main() {int tt, i, j; scanf("%d", &T); for(tt = 1; tt <= T; tt++) {printf("Case %d:\n", tt); scanf("%d", &n); for(i = 0; i < n; i++)for(j = 0; j < n; j++) { ll[i][j] = 0; jiao[i][j] = 0.0;} for(i = 0; i < n; i++) {scanf("%I64d%I64d", &p[i].x, &p[i].y); p[i].id = i; for(j = 0; j < n; j++) { s[j].p[i] = p[i];}} for(i = 0; i < n; i++) { ss = p[i]; qsort(s[i].p, n, sizeof(s[i].p[0]), cmp); for(j = 0; j < n; j++) l[i][s[i].p[j].id] = j;} scanf("%d", &m); int num; struct npoint q[3]; for(i = 0; i < m; i++) {for(j = 0; j < 3; j++) {scanf("%d", &num); q[j].x = p[num].x; q[j].y = p[num].y; q[j].id = num;} qsort(q, 3, sizeof(q[0]), cmp2); long long ans = 0; if(cross(q[1], q[2], q[0]) > 0) { ans += lfind(q[0].id, q[2].id, 1); ans += lfind(q[0].id, q[1].id, 0); ans += lfind(q[1].id, q[2].id, 0); ans += rfind(q[0].id, q[2].id, q[1].id); ans += rfind(q[1].id, q[0].id, q[2].id); ans += rfind(q[2].id, q[1].id, q[0].id);} else { ans += lfind(q[0].id, q[2].id, 0); ans += lfind(q[0].id, q[1].id, 1); ans += lfind(q[1].id, q[2].id, 1); ans += rfind(q[0].id, q[1].id, q[2].id); ans += rfind(q[1].id, q[2].id, q[0].id); ans += rfind(q[2].id, q[0].id, q[1].id);} ans = ans - 2 * (n - 3); printf("%I64d\n", ans);}} return 0;}
