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

struct edge {
    int u, v, pre;
} E[2000];

int head[2000], ccnt;
void add_edge(int u, int v) {
    E[ccnt].u = u;
    E[ccnt].v = v;
    E[ccnt].pre = head[u];
    head[u] = ccnt++;
}

int id,mxdep;
void dfs(int u,int pre,int dep)
{
    //printf("u = %d\n",u);
    if(dep>mxdep)
    {
        mxdep=dep;
        id=u;
    }
    for(int e=head[u];~e;e=E[e].pre)
    {
        int v = E[e].v;
        if(v==pre)continue;
        //printf("%d -> %d\n",u,v);
        dfs(v,u,dep+1);
    }
}

class TheTree {
    public:
        int maximumDiameter(vector <int> cnt) {
            int n  = cnt.size();
            ccnt = 0;
            memset(head, -1, sizeof(head));
            int m = 1, pre1 = 1, pre2 = 1;
            for(int i = 0; i < n; ++i) {
                if(cnt[i] >= 2)cnt[i] = 2;
                if(cnt[i] == 1) {
                    ++m;
                    add_edge(pre1, m);
                    add_edge(m, pre1);
                    pre1=pre2=m;
                }
                else {
                    ++m;
                    add_edge(pre1, m);
                    add_edge(m, pre1);
                    pre1 = m;
                    ++m;
                    add_edge(pre2, m);
                    add_edge(m, pre2);
                    pre2 = m;
                }
            }
            id=-1;
            mxdep=-1;
            dfs(1,1,0);
            //printf("id = %d, mxdep = %d\n",id,mxdep);
            dfs(id,id,0);
            return mxdep;
        }
};

double test0() {
    int t0[] = {3};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    TheTree * obj = new TheTree();
    clock_t start = clock();
    int my_answer = obj->maximumDiameter(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 2;
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
    int t0[] = {2, 2};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    TheTree * obj = new TheTree();
    clock_t start = clock();
    int my_answer = obj->maximumDiameter(p0);
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
double test2() {
    int t0[] = {4, 1, 2, 4};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    TheTree * obj = new TheTree();
    clock_t start = clock();
    int my_answer = obj->maximumDiameter(p0);
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
double test3() {
    int t0[] = {4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    TheTree * obj = new TheTree();
    clock_t start = clock();
    int my_answer = obj->maximumDiameter(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 21;
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

    if(!errors)
        cout << "You're a stud (at least on the example cases)!" << endl;
    else
        cout << "Some of the test cases had errors." << endl;
}


//Powered by [KawigiEdit] 2.0!
