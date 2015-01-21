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
typedef long long LL;
class AstronomicalRecords {
    public:
        int minimalPlanets(vector <int> A, vector <int> B) {
            int n = A.size();
            int m = B.size();
            vector<LL> a, b;
            for(int i = 0; i < n; ++i) {
                a.push_back(A[i]);
                b.push_back(B[i]);
            }
            int res = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    vector<LL> ta = a, tb = b;
                    for(int k = 0; k < n; ++k) {
                        ta[k] *= b[j];
                        tb[k] *= a[i];
                    }
                    int dp[55][55];

                    for(int u = 0; u < n; ++u) {
                        for(int v = 0; v < m; ++v) {
                            dp[u][v] = 0;
                        }
                    }
                    for(int u = 0; u < n; ++u) {
                        for(int v = 0; v < m; ++v) {
                            dp[u][v] = 0;
                            if(ta[u] == tb[v]) {
                                ++dp[u][v];
                                if(u && v)dp[u][v] += dp[u-1][v-1];
                            }
                            if(u)dp[u][v] = max(dp[u-1][v], dp[u][v]);
                            if(v)dp[u][v] = max(dp[u][v-1], dp[u][v]);
                        }
                    }
                    res = max(res, dp[n-1][m-1]);
                }
            }
            return n + m - res;
        }
};
double test0() {
    int t0[] = {1, 2, 1, 2, 1};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = {2, 1, 2, 1, 2};
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    AstronomicalRecords * obj = new AstronomicalRecords();
    clock_t start = clock();
    int my_answer = obj->minimalPlanets(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 6;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p2 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test1() {
    int t0[] = {1, 2, 3, 4};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = {2, 4, 6, 8};
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    AstronomicalRecords * obj = new AstronomicalRecords();
    clock_t start = clock();
    int my_answer = obj->minimalPlanets(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 4;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p2 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test2() {
    int t0[] = {2, 3, 2, 3, 2, 3, 2};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = {600, 700, 600, 700, 600, 700, 600};
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    AstronomicalRecords * obj = new AstronomicalRecords();
    clock_t start = clock();
    int my_answer = obj->minimalPlanets(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 10;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p2 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test3() {
    int t0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = {6, 7, 8, 9, 10, 11, 12};
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    AstronomicalRecords * obj = new AstronomicalRecords();
    clock_t start = clock();
    int my_answer = obj->minimalPlanets(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 12;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p2 != my_answer) {
        cout << "DOESN'T MATCH!!!!" << endl << endl;
        return -1;
    }
    else {
        cout << "Match :-)" << endl << endl;
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
}
double test4() {
    int t0[] = {100000000, 200000000};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = {200000000, 100000000};
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    AstronomicalRecords * obj = new AstronomicalRecords();
    clock_t start = clock();
    int my_answer = obj->minimalPlanets(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 3;
    cout << "Desired answer: " << endl;
    cout << "\t" << p2 << endl;
    cout << "Your answer: " << endl;
    cout << "\t" << my_answer << endl;
    if(p2 != my_answer) {
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
