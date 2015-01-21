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

class FoxAndFencing {
    public:
        string WhoCanWin(int, int, int, int, int);
};

string FoxAndFencing::WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
    string ret = "";
    if(mov1 + rng1 >= d) {
        ret = "Ciel";
    }
    else {
        if(mov2 + rng2 >= d + mov1) {
            ret = "Liss";
        }
        else {
            if(mov1 > mov2 && mov1 + rng1 > 2 * mov2 + rng2) {
                ret = "Ciel";
            }
            else {
                if(mov2 > mov1 && mov2 + rng2 > 2 * mov1 + rng1) {
                    ret = "Liss";
                }
                else {
                    ret = "Draw";
                }
            }
        }
    }
    return ret;
}
double test0() {
    int p0 = 1;
    int p1 = 58;
    int p2 = 1;
    int p3 = 58;
    int p4 = 2;
    FoxAndFencing * obj = new FoxAndFencing();
    clock_t start = clock();
    string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    string p5 = "Ciel";
    cout << "Desired answer: " << endl;
    cout << "\t\"" << p5 << "\"" << endl;
    cout << "Your answer: " << endl;
    cout << "\t\"" << my_answer << "\"" << endl;
    if(p5 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test1() {
    int p0 = 2;
    int p1 = 1;
    int p2 = 1;
    int p3 = 100;
    int p4 = 50;
    FoxAndFencing * obj = new FoxAndFencing();
    clock_t start = clock();
    string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    string p5 = "Liss";
    cout << "Desired answer: " << endl;
    cout << "\t\"" << p5 << "\"" << endl;
    cout << "Your answer: " << endl;
    cout << "\t\"" << my_answer << "\"" << endl;
    if(p5 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test2() {
    int p0 = 2;
    int p1 = 1;
    int p2 = 1;
    int p3 = 100;
    int p4 = 150;
    FoxAndFencing * obj = new FoxAndFencing();
    clock_t start = clock();
    string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    string p5 = "Draw";
    cout << "Desired answer: " << endl;
    cout << "\t\"" << p5 << "\"" << endl;
    cout << "Your answer: " << endl;
    cout << "\t\"" << my_answer << "\"" << endl;
    if(p5 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test3() {
    int p0 = 100;
    int p1 = 100;
    int p2 = 100;
    int p3 = 100;
    int p4 = 100000000;
    FoxAndFencing * obj = new FoxAndFencing();
    clock_t start = clock();
    string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    string p5 = "Draw";
    cout << "Desired answer: " << endl;
    cout << "\t\"" << p5 << "\"" << endl;
    cout << "Your answer: " << endl;
    cout << "\t\"" << my_answer << "\"" << endl;
    if(p5 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test4() {
    int p0 = 100;
    int p1 = 1;
    int p2 = 100;
    int p3 = 1;
    int p4 = 100000000;
    FoxAndFencing * obj = new FoxAndFencing();
    clock_t start = clock();
    string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    string p5 = "Ciel";
    cout << "Desired answer: " << endl;
    cout << "\t\"" << p5 << "\"" << endl;
    cout << "Your answer: " << endl;
    cout << "\t\"" << my_answer << "\"" << endl;
    if(p5 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test5() {
    int p0 = 100;
    int p1 = 1;
    int p2 = 100;
    int p3 = 250;
    int p4 = 100000000;
    FoxAndFencing * obj = new FoxAndFencing();
    clock_t start = clock();
    string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    string p5 = "Draw";
    cout << "Desired answer: " << endl;
    cout << "\t\"" << p5 << "\"" << endl;
    cout << "Your answer: " << endl;
    cout << "\t\"" << my_answer << "\"" << endl;
    if(p5 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test6() {
    int p0 = 100;
    int p1 = 1;
    int p2 = 100;
    int p3 = 150;
    int p4 = 100000000;
    FoxAndFencing * obj = new FoxAndFencing();
    clock_t start = clock();
    string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    string p5 = "Ciel";
    cout << "Desired answer: " << endl;
    cout << "\t\"" << p5 << "\"" << endl;
    cout << "Your answer: " << endl;
    cout << "\t\"" << my_answer << "\"" << endl;
    if(p5 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test7() {
    int p0 = 100;
    int p1 = 50;
    int p2 = 100;
    int p3 = 1;
    int p4 = 100000000;
    FoxAndFencing * obj = new FoxAndFencing();
    clock_t start = clock();
    string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    string p5 = "Ciel";
    cout << "Desired answer: " << endl;
    cout << "\t\"" << p5 << "\"" << endl;
    cout << "Your answer: " << endl;
    cout << "\t\"" << my_answer << "\"" << endl;
    if(p5 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test8() {
    int p0 = 100;
    int p1 = 150;
    int p2 = 100;
    int p3 = 1;
    int p4 = 100000000;
    FoxAndFencing * obj = new FoxAndFencing();
    clock_t start = clock();
    string my_answer = obj->WhoCanWin(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    string p5 = "Draw";
    cout << "Desired answer: " << endl;
    cout << "\t\"" << p5 << "\"" << endl;
    cout << "Your answer: " << endl;
    cout << "\t\"" << my_answer << "\"" << endl;
    if(p5 != my_answer) {
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

    time = test6();
    if(time < 0)
        errors = true;

    time = test7();
    if(time < 0)
        errors = true;

    time = test8();
    if(time < 0)
        errors = true;

    if(!errors)
        cout << "You're a stud (at least on the example cases)!" << endl;
    else
        cout << "Some of the test cases had errors." << endl;
}


//Powered by [KawigiEdit] 2.0!
