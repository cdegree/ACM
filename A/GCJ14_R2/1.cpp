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
int p[22];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

class SixteenBricks {
public:
    bool in(int x,int y) {
        return x>=0&&x<4&&y>=0&&y<4;
    }
    int maximumSurface(vector <int> h) {
        vector<int> f = h;
        sort(f.begin(),f.end());


        int ID[]={7,11,3,8,10,0,15,2,4,14,1,12,9,5,13,6};
        for(int i=0;i<16;++i)
        {
            p[i]=f[ ID[i] ];
        }
        int q1=0,q2=0;
        int x=0,y=0;
        int cnt=0;
/*
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; ++j) {
                    printf("%d , %d\n",x,y);
                int id = x*4+y;
                if(cnt&1) {
                    p[id]=f[q1++];
                } else {
                    p[id]=h[q2++];
                }
                if(x&1) {
                    --y;
                } else {
                    ++y;
                }
                if(y==4||y==-1) {
                    ++x;
                    if(x&1) {
                        y=3;
                    } else {
                        y=0;
                    }
                }
                ++cnt;
            }
        }*/


        int res=16;
        for(int i=0; i<4; ++i){for(int j=0;j<4;++j)printf("%4d",p[i*4+j]);
        puts("");}
        for(int i=0; i<4; ++i) {
            for(int j=0; j<4; ++j) {
                int add = p[i*4+j]*4;
                for(int k=0; k<4; ++k) {
                    int nx = dx[k]+i;
                    int ny = dy[k]+j;
                    if(in(nx,ny)) {
                        int id = nx*4+ny;
                        add -= min(p[i*4+j],p[id]);
                    }
                }
                printf("add = %d\n",add);
                res += add;
            }
        }
        return res;
    }
};
double test0() {
    int t0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    SixteenBricks * obj = new SixteenBricks();
    clock_t start = clock();
    int my_answer = obj->maximumSurface(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 32;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1() {
    int t0[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    SixteenBricks * obj = new SixteenBricks();
    clock_t start = clock();
    int my_answer = obj->maximumSurface(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 64;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    } else {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2() {
    int t0[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59}
               ;
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    SixteenBricks * obj = new SixteenBricks();
    clock_t start = clock();
    int my_answer = obj->maximumSurface(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 1798;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer) {
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}


//Powered by [KawigiEdit] 2.0!
