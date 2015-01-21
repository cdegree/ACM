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
typedef unsigned int ui;
const int N = 1025;
struct PolicyGroup {
    int n;
    ui from[16], to[16];
    bool Located(ui ip1, ui ip2) {
        bool ok1 = 0, ok2 = 0;
        for(int i = 0; i < n; ++i) {
            if(from[i] <= ip1 && ip1 <= to[i])ok1 = 1;
            if(from[i] <= ip2 && ip2 <= to[i])ok2 = 1;
        }
        return ok1 && ok2;
    }
    bool enable;
} P[N];
set<int> st;
set<int>::iterator it;
char op[3];
void Read_E() {
    int id, n;
    scanf("%d", &id);
    st.insert(id);
    scanf("%d", &n);
    P[id].n = n;
    ui e[6];
    for(int i = 0; i < n; ++i) {
        scanf("%u.%u.%u.%u/%u", e + 3, e + 2, e + 1, e, e + 4);
        ui from = (e[0] + (e[1] << 8) + (e[2] << 16) + (e[3] << 24)) & (((1u << e[4]) - 1) << (32 - e[4]));
        ui to = ((1u << (32 - e[4])) - 1) | from;
        P[id].from[i] = from;
        P[id].to[i] = to;
    }
    P[id].enable = true;
}
void Read_D() {
    int id;
    scanf("%d", &id);
    st.erase(id);
    P[id].enable = false;
}
inline ui Read_IP() {
    ui e[5];
    scanf("%u.%u.%u.%u", e + 3, e + 2, e + 1, e);
    return e[0] + (e[1] << 8) + (e[2] << 16) + (e[3] << 24);
}
inline bool contain(LL from, LL to, LL ip) {
    return ip >= from && ip <= to;
}
void Read_F() {
    ui src, dest;
    src = Read_IP();
    dest = Read_IP();
    bool OK = false;
    for(it = st.begin(); it != st.end(); ++it) {
        int i = *it;
        if(P[i].enable && P[i].Located(src, dest)) {
            OK = 1;
        }
    }
    printf("%s\n", OK ? "F" : "D");
}

int main() {
    //st.clear();
    freopen("Bin.txt", "r", stdin);
    while(scanf("%s", op) != EOF) {
        if(op[0] == 'E') {
            Read_E();
        }
        else if(op[0] == 'D') {
            Read_D();
        }
        else {
            Read_F();
        }
    }
    return 0;
}
