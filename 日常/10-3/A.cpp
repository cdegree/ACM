/********************

Author:Cdegree

********************/
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
typedef unsigned long long uLL;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

uLL a[12], b[12];
char s[33];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        uLL sum = 0;

        for(int i = 0; i < 12; ++i) {
            //scanf("%s",s);
            scanf("%I64u.%I64u", a + i, b + i);
            sum += a[i] * 100 + b[i];
        }
        //cin>>sum;
        uLL res = sum / 12;
        uLL rm = sum % 12;
        if(rm >5) {
            ++res;
        }
        //printf("rm = %llu sum = %llu\n",rm,sum);
        printf("$");
        if(res % 100 == 0) {
            printf("%I64u\n", res / 100);
        }
        else if(res % 10 == 0) {
            printf("%I64u.%I64u\n", res / 100, (res / 10) % 10);
        }
        else {
            printf("%I64u.%02I64u\n", res / 100, res % 100);
        }
    }
    return 0;
}
