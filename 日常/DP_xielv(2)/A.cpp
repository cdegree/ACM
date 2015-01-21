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

const int N = 1000005;
char s[11];

pair<int, int> deq[N];


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int front = 0, tail = -1, v, i = 0, j = -1;
        while(~scanf("%s", s)) {
            if(s[0] == 'E') {
                break;
            }
            else if(s[0] == 'C') {
                scanf("%s", s);
                scanf("%d", &v);
                ++j;
                pair<int, int> pi;
                pi.X = j;
                pi.Y = v;
                if(front > tail) {

                    deq[++tail] = pi;
                }
                else {
                    while(front <= tail && deq[tail].Y < v) {
                        --tail;
                    }
                    deq[++tail] = pi;
                }
            }
            else if(s[0] == 'Q') {
                if(front <= tail) {
                    printf("%d\n", deq[front].Y);
                }
                else puts("-1");
            }
            else {
                ++i;
                if(deq[front].X < i)++front;
            }
        }
    }
    return 0;
}
