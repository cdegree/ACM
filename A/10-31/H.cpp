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


char s1[88], s2[88];
int cnt1[26], cnt2[26];
int main() {
    int T;
    //printf("%c\n",32);
    scanf("%d", &T);
    gets(s1);
    for(int t = 1; t <= T; ++t) {
        gets(s1);
        gets(s2);
        //puts(s1);
        //puts(s2);
        int n1 = strlen(s1);
        int n2 = strlen(s2);
        //printf("%d %d\n",n1,n2);
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        //puts("ok");
        for(int i = 0; i < n1; ++i) {
            if(!isalpha(s1[i]))break;
            //printf("%d\n",s1[i]);
            cnt1[ s1[i] - 'a' ]++;
        }
       // puts("ok");
        for(int i = 0; i < n2; ++i) {
            if(!isalpha(s2[i]))break;
            cnt2[ s2[i] - 'a' ]++;
        }
        //puts("ok");
        int res = 0;
        for(int i = 0; i < 26; ++i) {
            res += abs(cnt1[i] - cnt2[i]);
        }
        printf("Case #%d:  %d\n", t, res);
    }
    return 0;
}
