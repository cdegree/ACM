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
int b;

bool cmp(int a,int c) {
    return c<a;
}
bool OK(int cnt,int m,vector<int> h) {
    bool ok=false;
    int n = h.size();
    int ccnt=cnt;
    for(b=1; b<=50; ++b) {
        sort(h.begin(),h.end());
        int f=0;
        cnt=ccnt;
        while(f<n&&h[f]<=b)++f;
        sort(h.begin(),h.begin()+f,cmp);
        if(n==4&&b==19) {
            printf("cnt = %d\n",ccnt);
            printf("b = %d\n",b);
            for(int i=0; i<n; ++i) {
                printf("%d ",h[i]);
            }
            printf("ok = %d",ok);
            puts("");
        }
        bool enough=true;
        for(int i=0; i<m; ++i) {
            if(b<h[i]||cnt<b-h[i]) {
                enough=false;
                break;
            } else {
                cnt -= (b-h[i]);
            }
            if(n==4&&b==19) {
                printf("nowcnt = %d\n",cnt);
            }
        }
        if(enough) {
            ok=true;
            break;
        }
    }
    if(n==4&&0) {
        printf("cnt = %d\n",ccnt);
        printf("b = %d\n",b);
        for(int i=0; i<n; ++i) {
            printf("%d ",h[i]);
        }
        printf("ok = %d",ok);
        puts("");
    }
    return ok;
}
class BuildingHeightsEasy {
public:
    int minimum(int, vector <int>);
};

int BuildingHeightsEasy::minimum(int M, vector <int> heights) {

    int ret=0;
    while(!OK(ret,M,heights))ret++;
    return ret;
}


double test0() {
    int p0 = 2;
    int t1[] = {1, 2, 1, 4, 3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    BuildingHeightsEasy * obj = new BuildingHeightsEasy();
    clock_t start = clock();
    int my_answer = obj->minimum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int p0 = 3;
    int t1[] = {1, 3, 5, 2, 1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    BuildingHeightsEasy * obj = new BuildingHeightsEasy();
    clock_t start = clock();
    int my_answer = obj->minimum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int p0 = 1;
    int t1[] = {43, 19, 15};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    BuildingHeightsEasy * obj = new BuildingHeightsEasy();
    clock_t start = clock();
    int my_answer = obj->minimum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3() {
    int p0 = 3;
    int t1[] = {19, 23, 9, 12};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    BuildingHeightsEasy * obj = new BuildingHeightsEasy();
    clock_t start = clock();
    int my_answer = obj->minimum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 15;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4() {
    int p0 = 12;
    int t1[] = {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    BuildingHeightsEasy * obj = new BuildingHeightsEasy();
    clock_t start = clock();
    int my_answer = obj->minimum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 47;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
