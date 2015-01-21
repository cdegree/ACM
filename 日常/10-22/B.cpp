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

typedef unsigned int ui;
const int N = 1024;
struct Policy {
    vector< pair<ui, ui> > subset;
    bool Located(ui IPa, ui IPb) {
        int n = subset.size();
        bool ok1 = false, ok2 = false;
        for(int i = 0; i < n; ++i) {
            if(subset[i].X <= IPa && IPa <= subset[i].Y) {
                ok1 = true;
            }
            if(subset[i].X <= IPb && IPb <= subset[i].Y) {
                ok2 = true;
            }
        }
        return ok1 && ok2;
    }
    bool enable;
} P[N];
char ch[3];

pair<ui, ui> Input_Subset() {
    ui d[5];
    scanf("%d.%d.%d.%d/%d", d, d + 1, d + 2, d + 3, d + 4);
    ui IPa = (d[0] << 24) + (d[1] << 16) + (d[2] << 8) + d[3];
    ui IPb = IPa | ((1LL << (32 - d[4])) - 1);
    pair<ui, ui> ret;
    ret.X = IPa;
    ret.Y = IPb;
    return ret;
}

ui Input_IP() {
    ui d[4];
    scanf("%d.%d.%d.%d", d, d + 1, d + 2, d + 3);
    ui IP = (d[0] << 24) + (d[1] << 16) + (d[2] << 8) + d[3];
    return IP;
}

int main() {
    //freopen("Bin.txt", "r", stdin);
    for(int i = 0; i < N; ++i) {
        P[i].subset.clear();
        P[i].enable = false;
    }
    int id, n;
    while(~scanf("%s", ch)) {
        if(ch[0] == 'E') {
            scanf("%d%d", &id, &n);
            --id;
            P[id].enable = true;
            P[id].subset.clear();
            for(int i = 0; i < n; ++i) {
                pair<ui, ui> in = Input_Subset();
                //printf("%u.%u\n", in.X, in.Y);
                P[id].subset.push_back(in);
            }
        }
        else if(ch[0] == 'D') {
            scanf("%d", &id);
            --id;
            P[id].enable = false;
        }
        else {
            ui IPa = Input_IP();
            ui IPb = Input_IP();
            //printf("%u,%u\n", IPa, IPb);
            bool IN = false;
            for(int i = 0; i < N; ++i) {
                if(P[i].enable && P[i].Located(IPa, IPb)) {
                    IN = true;
                }
            }
            printf("%s\n", IN ? "F" : "D");
        }
    }
    return 0;
}
