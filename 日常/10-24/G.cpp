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


int S[100005];
bool Input_Int(int len) {
    char c;
    int sum = 0;
    while((c = getchar()) == ' ');
    while(c >= '0' && c <= '9') {
        sum = sum * 10 + (c - '0');
        c = getchar();
    }
    S[len] = sum;
    if(c == '\n' || c == '\0')return false;
    return true;
}
int main() {
    //freopen("Gin.txt", "r", stdin);
    int D, P;
    while(~scanf("%d%d", &D, &P)) {
        int n = 0;
        while(Input_Int(n++));
        for(int i = 0; i < n; ++i) {
            //printf("%d ", S[i]);
        } //puts("");
        if(S[0] > P) {
            puts("The spider is going to fall!");
        }
        else if(n == D + 1 && S[D] <= P) {
            puts("The spider may fall!");
        }
        else {
            int res = 0;
            if(n < D + 1) {
                //puts("H");
                int k1 = 0, k2 = 0;
                if((S[0] * S[2] - S[1] * S[1]) != 0) {
                    k1 = (S[0] * S[3] - S[1] * S[2]) / (S[0] * S[2] - S[1] * S[1]);
                    k2 = (S[2] * S[2] - S[1] * S[3]) / (S[0] * S[2] - S[1] * S[1]);
                }
                else {
                    k2 = 0;
                    if(S[1] != 0)k1 = S[2] / S[1];
                    else k1 = 0;
                }
                for(int i = n; i <= D; ++i) {
                    S[i] = k1 * S[i-1] + k2 * S[i-2];
                    if(S[i] > P)S[i] = P + 1;
                }
                for(int i = 0; i <= D; ++i) {
                    //printf("%3d", S[i]);
                } //puts("");
            }
            for(int i = 1; i <= D; ++i) {
                if(S[i] > P) {
                    res = D - i + 1;
                    break;
                }
            }

            if(S[D] <= P) {
                puts("The spider may fall!");
            }
            else printf("%d\n", res);
        }
    }
    return 0;
}
