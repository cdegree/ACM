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
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}



int main() {
    double X, Y, P, Q;
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%lf %lf %lf %lf", &X, &Y, &P, &Q);
        double tiger = (1 - Q) * X + Q * P * X + Q * P * Y;
        double wolf = Q * Y + (1 - Q) * P * X + (1 - Q) * P * Y;
        if(tiger > wolf) {
            printf("tiger %.4f\n", tiger);
        }
        else {
            printf("wolf %.4f\n", wolf);
        }
    }
    return 0;
}
