#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <bitset>
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
const double eps = 1e-8;
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

struct ant {
    char dir[3];
    double pos;
    char s[255];
} a[32000+5];

int main() {
    int n;
    double L, V;
    while(~scanf("%d", &n)) {
        if(n == 0)break;
        scanf("%lf %lf", &L, &V);
        int cnttop = 0, cntton = 0;
        double leftmostT = -10;
        double rightmostT = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%s %lf %s", a[i].dir, &a[i].pos, a[i].s);
        }

        //printf("%.2f %.2f\n",leftmostT,rightmostT);
        int id1 ;
        int id2;
        int id;
        double res = 0;

        int left = 0, right = n - 1;
        int preid = -1;
        while(0 && left < n && fabs(a[left].pos - 0) < eps) {
            preid = left;
            ++left;
        }
        while(0 && right >= 0 && fabs(a[right].pos - L) < eps) {
            preid = right;
            --right;
        }
        for(int i = left; i <= right; ++i) {
            if(a[i].dir[0] == 'p' || a[i].dir[0] == 'P') {
                cnttop++;
                if(leftmostT < -3) {
                    leftmostT = (L - a[i].pos) / V;
                }
            }
            else {
                cntton++;
                rightmostT = a[i].pos / V;
            }
        }
        id1 = left + cntton - 1;
        id2 = left + cntton;
        if(id1 < left) {
            if(id2 > right) {
                id = preid;
                res = 0;
            }
            else {
                id = id2;
                res = leftmostT;
            }
        }
        else if(id2 > right) {
            id = id1;
            res = rightmostT;
        }
        else {
            if(leftmostT < rightmostT) {
                id = id1;
                res = rightmostT;
            }
            else {
                id = id2;
                res = leftmostT;
            }
        }
        res *= 100;
        LL tmp = res + eps;
        res = tmp / 100.0;
        printf("%13.2f %s\n", res, a[id].s);
    }
    return 0;
}
