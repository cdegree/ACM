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

const int N = 57;
struct person {
    int val;
    int pre, next;
} P[N];

int main() {
    for(int i = 0; i < N; ++i) {
        P[i].val = i + 1;
        P[i].pre = (i - 1 + N) % N;
        P[i].next = (i + 1) % N;
        //printf("%d   %d   %d\n", P[i].val - 1, P[i].pre, P[i].next);
    }
    int last = -1;
    int st = 7;
    int cnt=0;
    while(1) {
        for(int j = 0; j < 10; ++j) {
            st = P[st].next;
        }
        P[ P[st].next ].pre = P[st].pre;
        P[ P[st].pre ].next = P[st].next;
        last = P[st].val;
        st = P[st].next;
        //printf("last = %d\n",last);
        if(P[st].next == P[st].pre)break;
    }
    printf("%d\n", last);
    return 0;
}
