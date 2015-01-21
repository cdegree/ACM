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

class TaroFriends
{
public:
    int getNumber(vector <int>, int);
};

int TaroFriends::getNumber(vector <int> c, int X)
{
    int n = c.size();
    sort(c.begin(),c.end());
    if(c[n-1]-c[0]<=X||X==0)
    {
        return c[n-1]-c[0];
    }
    else
    {
        int res=2e9;
        vector<int> odd = c, even = c;
        for(int i=0; i<c.size(); ++i)
        {
            int a = c[i];
            int rm = a%X;
            int b;
            if(a>=0)
            {
                b = a/X;
            }
            else
            {
                rm+=X;
                b = abs(a)/X+1;
            }
            if(b&1)
            {
                rm+=X;
            }
            c[i]=rm;
        }
        sort(c.begin(),c.end());
        puts("");
        for(int i=0; i<n; ++i)
        {
            printf("%d ",c[i]);
        }
        puts("");
        if(c[n-1]-c[0]<=X)
        {
            res = min(res,c[n-1]-c[0]);
        }
        else
        {
            for(int i=0; i<n; ++i)
            {
                vector<int> tmp = c;
                for(int j=0; j<i; ++j)
                {
                    tmp[j]=c[j]+X;
                }
                for(int j=i; j<n; ++j)
                {
                    tmp[j]=c[j]-X;
                }
                sort(tmp.begin(),tmp.end());
                if(tmp[n-1]-tmp[0]<=X)
                {
                    res = min(res,X);
                }
            }
        }
        return res;
    }
}

double test0()
{
    int t0[] = {-3, 0, 1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 3;
    TaroFriends * obj = new TaroFriends();
    clock_t start = clock();
    int my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 3;
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
    int t0[] = {4, 7, -7};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 5;
    TaroFriends * obj = new TaroFriends();
    clock_t start = clock();
    int my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 4;
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
    int t0[] = {-100000000, 100000000};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 100000000;
    TaroFriends * obj = new TaroFriends();
    clock_t start = clock();
    int my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 0;
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
    int t0[] = {3, 7, 4, 6, -10, 7, 10, 9, -5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 7;
    TaroFriends * obj = new TaroFriends();
    clock_t start = clock();
    int my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 7;
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
double test4()
{
    int t0[] = {-4, 0, 4, 0};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 4;
    TaroFriends * obj = new TaroFriends();
    clock_t start = clock();
    int my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 4;
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
double test5()
{
    int t0[] = {7};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 0;
    TaroFriends * obj = new TaroFriends();
    clock_t start = clock();
    int my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 0;
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

    time = test4();
    if (time < 0)
        errors = true;

    time = test5();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
