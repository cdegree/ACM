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

char c[33];
string s;



int mx_pa(string s) {
    int ret = 1;
    for(int i = 0; i < s.size(); ++i) {
        int l = i, r = i;
        while(l - 1 >= 0 && r + 1 < s.size() && s[l-1] == s[r+1]) {
            --l;
            ++r;
        }
        checkmax(ret, r - l + 1);
    }
    for(int i = 1; i < s.size(); ++i) {
        int l = i - 1, r = i;
        if(s[l] != s[r])continue;
        while(l - 1 >= 0 && r + 1 < s.size() && s[l-1] == s[r+1]) {
            --l;
            ++r;
        }
        checkmax(ret, r - l + 1);
    }
    return ret;
}
int mn;
set<string> st;
void gao(int u, int n) {
    if(u == n) {
        c[u] = '\0';
        s = c;
        //cout<<s<<endl;
        int cnt = mx_pa(s);
        if(mn > cnt) {
            mn=cnt;
            st.clear();
            st.insert(s);
        }
        else if(cnt == mn) {
            st.insert(s);
        }
    }
    else {
        c[u] = 'a';
        gao(u + 1, n);
        c[u] = 'b';
        gao(u + 1, n);
    }
}

int main() {
    int n, m;
    n=19;
    freopen("04out.txt","w",stdout);
    for(int i = 1; i <= n; ++i) {
        mn = 1e6;
        gao(0, i);
        string ans = *st.begin();
        printf(" \"%s\",\n",ans.c_str());
    }
    return 0;
}
