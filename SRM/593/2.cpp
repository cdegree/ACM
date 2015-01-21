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

vector< pair<int, int> > vp;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second < b.first + b.second;
}
const int N = 1000005;
int dp[2][N];
class MayTheBestPetWin {
    public:
        int calc(vector <int> A, vector <int> B) {
            int n = A.size();
            int S1 = 0, S2 = 0;
            for(int i = 0; i < n; ++i) {
                S1 += A[i];
                S2 += B[i];
            }
            memset(dp, -1, sizeof(dp));
            dp[0][0] = 1;
            int t1 = 0, t2 = 1;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(dp[0][j]==1) {
                        if(j - A[i] > -N/2)dp[1][j-A[i]+N/2] = 1;
                        if(j + B[i] < N/2)dp[1][j+B[i]+N/2] = 1;
                    }
                }
                for(int j = 0; j <N; ++j) {
                    dp[0][j] = dp[1][j];
                    dp[1][j] = -1;
                }
            }
            int tmp = S2 - S1;
            int res = 2e9;
            for(int i = 0; i <= 500000; ++i) {
                if(dp[0][i]==1)res = min(res, abs(i - tmp));
            }
            return res;
        }
};

double test0() {
    int t0[] = {3, 4, 4, 7};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = {3, 4, 4, 7};
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    MayTheBestPetWin * obj = new MayTheBestPetWin();
    clock_t start = clock();
    int my_answer = obj->calc(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 2;
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
    int t0[] = {1, 3, 5, 4, 5};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = {2, 5, 6, 8, 7};
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    MayTheBestPetWin * obj = new MayTheBestPetWin();
    clock_t start = clock();
    int my_answer = obj->calc(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 5;
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
    int t0[] = {2907, 949, 1674, 6092, 8608, 5186, 2630, 970, 1050, 2415, 1923, 2697, 5571, 6941, 8065, 4710, 716, 756, 5185, 1341, 993, 5092, 248, 1895, 4223, 1783, 3844, 3531, 2431, 1755, 2837, 4015};
    vector <int> p0(t0, t0 + sizeof(t0) / sizeof(int));
    int t1[] = {7296, 6954, 4407, 9724, 8645, 8065, 9323, 8433, 1352, 9618, 6487, 7309, 9297, 8999, 9960, 5653, 4721, 7623, 6017, 7320, 3513, 6642, 6359, 3145, 7233, 5077, 6457, 3605, 2911, 4679, 5381, 6574};
    vector <int> p1(t1, t1 + sizeof(t1) / sizeof(int));
    MayTheBestPetWin * obj = new MayTheBestPetWin();
    clock_t start = clock();
    int my_answer = obj->calc(p0, p1);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p2 = 52873;
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

    if(!errors)
        cout << "You're a stud (at least on the example cases)!" << endl;
    else
        cout << "Some of the test cases had errors." << endl;
}


//Powered by [KawigiEdit] 2.0!
