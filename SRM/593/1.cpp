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

int dx[] = { -1, -1, 1, 1, 0, 0};
int dy[] = {0, 1, -1, 0, -1, 1};
int mark[55][55];
vector <string> B;
int n;
int res;
class HexagonalBoard {
    public:
        int minColors(vector <string> b) {
            n = b.size();
            B = b;
            res = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(b[i][j] == 'X') {
                        res = 1;
                    }
                }
            }
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(b[i][j] == 'X') {
                        for(int k = 0; k < 6; ++k) {
                            int ni = i + dx[k];
                            int nj = j + dy[k];
                            if(ni >= 0 && nj >= 0 && ni < n && nj < n && b[ni][nj] == 'X') {
                                res = 2;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; ++i)for(int j = 0; j < n; ++j)mark[i][j] = -1;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(mark[i][j] == -1 && b[i][j] == 'X') {
                        dfs(i, j, 1);
                    }
                }
            }
            return res;
        }

        void dfs(int x, int y, int p) {
            mark[x][y] = p;
            for(int k = 0; k < 6; ++k) {
                int ni = x + dx[k];
                int nj = y + dy[k];
                if(ni >= 0 && nj >= 0 && ni < n && nj < n && B[ni][nj] == 'X') {
                    if(mark[ni][nj] == -1) {
                        mark[ni][nj] = p ^ 1;
                        dfs(ni, nj, p ^ 1);
                    }
                    else if(mark[ni][nj] == p ^ 1) {
                        ;
                    }
                    else {
                        res = 3;
                    }
                }
            }
        }

};
double test0() {
    string t0[] = {"---",
                   "---",
                   "---"
                  }
                  ;
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    HexagonalBoard * obj = new HexagonalBoard();
    clock_t start = clock();
    int my_answer = obj->minColors(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 0;
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
    string t0[] = {"-X--",
                   "---X",
                   "----",
                   "-X--"
                  };
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    HexagonalBoard * obj = new HexagonalBoard();
    clock_t start = clock();
    int my_answer = obj->minColors(p0);
    clock_t end = clock();
    delete obj;
    cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    int p1 = 1;
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
    string t0[] = {"XXXX",
                   "---X",
                   "---X",
                   "---X"
                  };
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    HexagonalBoard * obj = new HexagonalBoard();
    clock_t start = clock();
    int my_answer = obj->minColors(p0);
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
double test3() {
    string t0[] = {"XX-XX--"
                   , "-XX-XXX"
                   , "X-XX--X"
                   , "X--X-X-"
                   , "XX-X-XX"
                   , "-X-XX-X"
                   , "-XX-XX-"
                  };
    vector <string> p0(t0, t0 + sizeof(t0) / sizeof(string));
    HexagonalBoard * obj = new HexagonalBoard();
    clock_t start = clock();
    int my_answer = obj->minColors(p0);
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
