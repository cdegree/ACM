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

using namespace std;

class BinPacking {
    public:
        int minBins(vector <int> w) {
            int n = w.size();
            vector<int> bag[55];
            sort(w.rbegin(), w.rend());
            bool vis[55];
            for(int i = 0; i < n; ++i)vis[i] = 0;
            int ret = 0;
            int v = 0;
            for(int i = 0; i < n; ++i) {
                if(vis[i])continue;
                v += w[i];
                if(v > 200) {
                    ret++;
                    v = 0;
                }
                else {
                    for(int j = i + 1; j < n; ++j) {
                        if(!vis[j]&&v + w[j] <= 300) {
                            v+=w[j];
                            vis[j] = 1;
                            printf("j = %d\n",j);
                        }
                    }
                    ++ret;
                    v=0;
                }
                printf("w= %d , ret = %d\n",w[i],ret);
            }
            return ret;
        }
};

double test0() {
    int t0[] = {150, 150, 150, 150, 150};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    BinPacking * obj = new BinPacking();
    clock_t start = clock();
    int my_answer = obj->minBins(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 3;
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
    int t0[] = {130, 140, 150, 160};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    BinPacking * obj = new BinPacking();
    clock_t start = clock();
    int my_answer = obj->minBins(p0);
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
double test2() {
    int t0[] = {100, 100, 100, 100, 100, 100, 100, 100, 100};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    BinPacking * obj = new BinPacking();
    clock_t start = clock();
    int my_answer = obj->minBins(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 3;
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
    int t0[] = {100, 200, 100, 100, 100, 100, 200, 100, 200};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    BinPacking * obj = new BinPacking();
    clock_t start = clock();
    int my_answer = obj->minBins(p0);
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
double test4() {
    int t0[] = {157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    BinPacking * obj = new BinPacking();
    clock_t start = clock();
    int my_answer = obj->minBins(p0);
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

    if(!errors)
        cout << "You're a stud (at least on the example cases)!" << endl;
    else
        cout << "Some of the test cases had errors." << endl;
}


//Powered by [KawigiEdit] 2.0!
