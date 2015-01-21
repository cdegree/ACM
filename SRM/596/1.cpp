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
int dp[3005];
class IncrementAndDoubling {
    public:
        int getMin(vector <int> a) {
            int ret = 0;
            int n = a.size();
            while(1) {
                bool OK = true;
                for(int i = 0; i < n; ++i) {
                    if(a[i])OK = false;
                }
                if(OK)break;
                bool even = true;
                for(int i = 0; i < n; ++i) {
                    if(a[i] & 1)even = false;
                }
                if(even) {
                    for(int i = 0; i < n; ++i) {
                        a[i] /= 2;
                    }
                }
                else {
                    for(int i = 0; i < n; ++i) {
                        if(a[i]>0&&(a[i]&1)) {
                            --a[i];
                            break;
                        }
                    }
                }
                ++ret;
            }
            return ret ;
        }
};

double test0() {
    int t0[] = {2, 1};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    IncrementAndDoubling * obj = new IncrementAndDoubling();
    clock_t start = clock();
    int my_answer = obj->getMin(p0);
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
    int t0[] = {16, 16, 16};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    IncrementAndDoubling * obj = new IncrementAndDoubling();
    clock_t start = clock();
    int my_answer = obj->getMin(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 7;
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
    int t0[] = {100};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    IncrementAndDoubling * obj = new IncrementAndDoubling();
    clock_t start = clock();
    int my_answer = obj->getMin(p0);
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
double test3() {
    int t0[] = {0, 0, 1, 0, 1};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    IncrementAndDoubling * obj = new IncrementAndDoubling();
    clock_t start = clock();
    int my_answer = obj->getMin(p0);
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
double test4() {
    int t0[] = {123, 234, 345, 456, 567, 789};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    IncrementAndDoubling * obj = new IncrementAndDoubling();
    clock_t start = clock();
    int my_answer = obj->getMin(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 40;
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
    int t0[] = {7, 5, 8, 1, 8, 6, 6, 5, 3, 5, 5, 2, 8, 9, 9, 4, 6, 9, 4, 4, 1, 9, 9, 2, 8, 4, 7, 4, 8, 8, 6, 3, 9, 4, 3, 4, 5, 1, 9, 8, 3, 8, 3, 7, 9, 3, 8, 4, 4, 7};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    IncrementAndDoubling * obj = new IncrementAndDoubling();
    clock_t start = clock();
    int my_answer = obj->getMin(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 84;
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
