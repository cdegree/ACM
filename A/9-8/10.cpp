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


const int N = 2000005;

int prime[N];
bool isprime[N];
int len;
void init() {
    memset(isprime, 1, sizeof(isprime));
    len = 0;
    for(int i = 2; i < N; ++i) {
        if(isprime[i]) {
            for(int j = i + i; j < N; j += i) {
                isprime[j] = 0;
            }
            prime[len++] = i;
        }
    }
}

pair<int, int> gao(int x) {
    pair<int, int> ret;
    ret.X = ret.Y = 0;
    for(int i = 0; i < len; ++i) {
        if(prime[i] + x < N && isprime[prime[i] + x]) {
            ret.X = prime[i] + x;
            ret.Y = prime[i];
            break;
        }
    }
    return ret;
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while(T--)
        //int cnt=0;
        //for(int x=2;x<=1000000;x+=2)
    {
        int x;
        scanf("%d", &x);
        if(x < 0) {
            x=-x;
            pair<int, int> pi = gao(x);
            //if(pi.X==0||pi.Y==0)++cnt;
            printf("%d %d\n", pi.Y, pi.X);
        }
        else {
            pair<int, int> pi = gao(x);
            //if(pi.X==0||pi.Y==0)++cnt;
            printf("%d %d\n", pi.X, pi.Y);
        }
    }
    //printf("cnt=%d\n",cnt);
    return 0;
}
