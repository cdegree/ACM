#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int N = 5005;
const int E = 20005;
const int inf = 1000000000;
struct Edge {
    int en, cap, flow, next;
} edge[E];
int head[N] , now[N];
int src, dest, node, nedge;
int pre[N] , dis[N] , gap[N];

void add_edge(int st, int en, int cap) {
    edge[nedge].en = en;
    edge[nedge].cap = cap;
    edge[nedge].flow = 0;
    edge[nedge].next = head[st];
    head[st] = nedge++;

    edge[nedge].en = st;
    edge[nedge].cap = 0;
    edge[nedge].flow = 0;
    edge[nedge].next = head[en];
    head[en] = nedge++;
}

void augment(int flow) {
    for(int i = src; i != dest; i = edge[now[i]].en) {
        edge[now[i]].flow += flow;
        edge[now[i] ^ 1].flow -= flow;
    }
}

int sap() {
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < node; i++)
        now[i] = head[i];
    gap[0] = node;
    int point = src, flow = 0, min_flow = inf;
    while(dis[src] < node) {
        bool fg = false;
        for(int i = now[point]; ~i; i = edge[i].next)
            if(edge[i].cap - edge[i].flow > 0 && dis[point] == dis[edge[i].en] + 1) {
                min_flow = min(min_flow, edge[i].cap - edge[i].flow);
                now[point] = i;
                pre[edge[i].en] = point;
                point = edge[i].en;
                if(point == dest) {
                    flow += min_flow;
                    augment(min_flow);
                    point = src;
                    min_flow = inf;
                }
                fg = true;
                break;
            }
        if(fg) continue;
        if(--gap[dis[point]] == 0) break;
        int Min = node;
        for(int i = head[point]; ~i; i = edge[i].next)
            if(edge[i].cap - edge[i].flow > 0 && Min > dis[edge[i].en]) {
                Min = dis[edge[i].en];
                now[point] = i;
            }
        gap[dis[point] = Min + 1]++;
        if(point != src) point = pre[point];
    }
    return flow;
}

void init(int _node, int _src, int _dest) {
    nedge = 0;
    node = _node;
    src = _src;
    dest = _dest;
    for(int i = 0; i < node; i++)head[i] = -1;
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector <string> B;
class FoxAndGo3 {
    public:
        int maxEmptyCells(vector <string> b) {
            int n = b.size();
            init(n * n + 2, n * n, n * n + 1);
            int res = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(b[i][j] == 'o') {
                        ++res;
                        add_edge(src, i * n + j, 1);
                        for(int k = 0; k < 4; ++k) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                                add_edge(i * n + j, nx * n + ny, inf);
                            }
                        }
                    }
                    else if(b[i][j] == '.') {
                        ++res;
                        add_edge(i * n + j, dest, 1);
                    }
                }
            }
            return res - sap();
        }
};
double test0() {
    string t0[] = {"o.o",
                   ".o.",
                   "o.o"
                  };
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    FoxAndGo3 * obj = new FoxAndGo3();
    clock_t start = clock();
    int my_answer = obj->maxEmptyCells(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 5;
    cout << "Desired answer: " << endl;
    cout << "\t" << p1 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p1 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test1() {
    string t0[] = {"...",
                   ".o.",
                   "..."
                  }
                  ;
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    FoxAndGo3 * obj = new FoxAndGo3();
    clock_t start = clock();
    int my_answer = obj->maxEmptyCells(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 8;
    cout << "Desired answer: " << endl;
    cout << "\t" << p1 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p1 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test2() {
    string t0[] = {"xxxxx",
                   "xxoxx",
                   "xo.ox",
                   "xxoxx",
                   "xxxxx"
                  }
                  ;
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    FoxAndGo3 * obj = new FoxAndGo3();
    clock_t start = clock();
    int my_answer = obj->maxEmptyCells(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 4;
    cout << "Desired answer: " << endl;
    cout << "\t" << p1 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p1 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test3() {
    string t0[] = {".xox.",
                   ".o.ox",
                   "x.o.o",
                   "ox.ox",
                   ".ox.."
                  }
                  ;
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    FoxAndGo3 * obj = new FoxAndGo3();
    clock_t start = clock();
    int my_answer = obj->maxEmptyCells(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 12;
    cout << "Desired answer: " << endl;
    cout << "\t" << p1 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p1 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test4() {
    string t0[] = {"o.o.o",
                   ".ox..",
                   "oxxxo",
                   "..x..",
                   "o.o.o"
                  }
                  ;
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    FoxAndGo3 * obj = new FoxAndGo3();
    clock_t start = clock();
    int my_answer = obj->maxEmptyCells(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 12;
    cout << "Desired answer: " << endl;
    cout << "\t" << p1 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p1 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test5() {
    string t0[] = {"...",
                   "...",
                   "..."
                  };
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    FoxAndGo3 * obj = new FoxAndGo3();
    clock_t start = clock();
    int my_answer = obj->maxEmptyCells(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 9;
    cout << "Desired answer: " << endl;
    cout << "\t" << p1 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p1 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
int main() {
    int time;
    bool errors = false;

    time = test0();
    if(time < 0)
        errors = true;

    time = test1();
    if(time < 0)
        errors = true;

    time = test2();
    if(time < 0)
        errors = true;

    time = test3();
    if(time < 0)
        errors = true;

    time = test4();
    if(time < 0)
        errors = true;

    time = test5();
    if(time < 0)
        errors = true;

    if(!errors)
        cout << "You're a stud (at least on the example cases)!" << endl;
    else
        cout << "Some of the test cases had errors." << endl;
}


//Powered by [KawigiEdit] 2.0!
