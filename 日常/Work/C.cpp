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

const int N = 116502;
int prime[N];
bool isprime[N];
int len;
void init() {
    for(int i = 2; i < N; ++i)isprime[i] = 1;
    isprime[1] = 0;
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

const int arg = 116501;

void gao(int n) {
    int m = n;
    vector<int> res;
    for(int i = 0; i < len; ++i) {
        while(n % prime[i] == 0) {
            res.push_back(prime[i]);
            n /= prime[i];
        }
    }
    if(n > 1)res.push_back(n);
    printf("%d=", m);
    for(int i = 0; i < res.size(); ++i) {
        printf("%d%c", res[i], i == res.size() - 1 ? '\n' : '*');
    }
}

int main() {
    int n = arg;
    init();
    gao(n);
    return 0;
}
