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

class MinimumSquareEasy
{
public:
    long long minArea(vector <int>, vector <int>);
};
typedef long long LL;
int dx[]= {1,1,-1,-1};
int dy[]= {1,-1,1,-1};
long long MinimumSquareEasy::minArea(vector <int> x, vector <int> y)
{
    int n = x.size();

    long long l=2,r=2e9+5,res=-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        bool found=false;
        for(int i=0; i<n; ++i)
        {
            for(int k=0; k<4; ++k)
            {
                LL ox=dx[k]+x[i];
                LL oy=dy[k]+y[i];
                LL ex=ox-dx[k]*mid;
                LL ey=oy-dy[k]*mid;
                //if(x[0]==1000000000)printf("%lld %lld %lld %lld\n",ox,oy,ex,ey);
                LL mnx=min(ox,ex);
                LL mny=min(oy,ey);
                LL mxx=max(ox,ex);
                LL mxy=max(oy,ey);
                int cnt=0;
                for(int j=0; j<n; ++j)
                {
                    if( x[j]>mnx&&x[j]<mxx&&y[j]>mny&&y[j]<mxy )
                    {
                        ++cnt;
                    }
                }
                //printf("%d %d\n",n,cnt);
                if(cnt>=n-2)
                {
                    found=true;
                    break;
                }
            }
        }
        //printf("%lld\n",mid);
        if(found)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res*res;
}
double test0()
{
    int t0[] = {0, 1, 2};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {0, 1, 5};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    MinimumSquareEasy * obj = new MinimumSquareEasy();
    clock_t start = clock();
    long long my_answer = obj->minArea(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 4LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1()
{
    int t0[] = {-1, -1, 0, 2, 0};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {-2, -1, 0, -1, -2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    MinimumSquareEasy * obj = new MinimumSquareEasy();
    clock_t start = clock();
    long long my_answer = obj->minArea(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 9LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2()
{
    int t0[] = {1000000000, -1000000000, 1000000000, -1000000000};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1000000000, 1000000000, -1000000000, -1000000000};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    MinimumSquareEasy * obj = new MinimumSquareEasy();
    clock_t start = clock();
    long long my_answer = obj->minArea(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 4000000008000000004LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3()
{
    int t0[] = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    MinimumSquareEasy * obj = new MinimumSquareEasy();
    clock_t start = clock();
    long long my_answer = obj->minArea(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 22801LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
int main()
{
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
