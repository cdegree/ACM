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

typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

char tod[] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6 , 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

char s[8];

string stod(string p) {
    string ret = "";
    for(int i = 0; i < p.size(); ++i) {
        ret += tod[ p[i] - 'a' ]+'0';
    }
    return ret;
}
map<string, int>::iterator it;
map<string, int> mp;
int cnt[5005];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        mp.clear();
        int n, m;
        memset(cnt,0,sizeof(cnt));
        string pat;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            pat = s;
            mp[pat] = i;
        }
        for(int j = 0; j < m; ++j) {
            scanf("%s", s);
            pat = s;
            pat=stod(pat);
            //cout<<pat<<endl;
            ++cnt[mp[pat]];
        }
        for(int i = 0; i < n; ++i) {
            printf("%d\n",cnt[i]);
        }
    }
    return 0;
}
