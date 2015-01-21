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

class EllysScrabble {
public:
    string getMin(string, int);
};

string EllysScrabble::getMin(string s, int D) {
    string ret=s;
    bool used[55];
    for(int i=0; i<55; ++i)used[i]=false;
    int n = s.size();
    for(int i=0; i<n; ++i) {
        if(i-D>=0&&!used[i-D]) {
            ret[i]=s[i-D];
            used[i-D]=1;
        } else {
            int mn='Z'+1;
            int p=-1;
            for(int j=max(0,i-D); j<=min(n-1,i+D); ++j) {
                if(!used[j]&&mn>s[j]) {
                    mn=s[j];
                    p=j;
                }
            }
            used[p]=1;
            ret[i]=s[p];
        }
    }
    return ret;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
    string p0 = "TOPCODER";
    int p1 = 3;
    EllysScrabble * obj = new EllysScrabble();
    clock_t start = clock();
    string my_answer = obj->getMin(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "CODTEPOR";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    string p0 = "ESPRIT";
    int p1 = 3;
    EllysScrabble * obj = new EllysScrabble();
    clock_t start = clock();
    string my_answer = obj->getMin(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "EIPRST";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    string p0 = "BAZINGA";
    int p1 = 8;
    EllysScrabble * obj = new EllysScrabble();
    clock_t start = clock();
    string my_answer = obj->getMin(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "AABGINZ";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    string p0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int p1 = 9;
    EllysScrabble * obj = new EllysScrabble();
    clock_t start = clock();
    string my_answer = obj->getMin(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    string p0 = "GOODLUCKANDHAVEFUN";
    int p1 = 7;
    EllysScrabble * obj = new EllysScrabble();
    clock_t start = clock();
    string my_answer = obj->getMin(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "CADDGAHEOOFLUKNNUV";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test5() {
    string p0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
    int p1 = 6;
    EllysScrabble * obj = new EllysScrabble();
    clock_t start = clock();
    string my_answer = obj->getMin(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test6() {
    string p0 = "ABRACADABRA";
    int p1 = 2;
    EllysScrabble * obj = new EllysScrabble();
    clock_t start = clock();
    string my_answer = obj->getMin(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "AABARACBDAR";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
int main() {
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    time = test5();
    if (time < 0)
        errors = true;

    time = test6();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

