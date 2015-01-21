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

class TheNumberGame
{
public:
    string determineOutcome(int A, int B)
    {
        vector<int> a,b;
        a = todig(A);
        b = todig(B);
        int n1 = a.size();
        int n2 = b.size();
        if(n2>n1)return "Manao loses";
        if(equal(a,b))return "Manao wins";
        else return "Manao loses";
    }
    vector<int> todig(int A)
    {
        vector<int> a;
         a.clear();
        while(A>0)
        {
            a.push_back(A%10);
            A/=10;
        }
        return a;
    }
    bool equal(vector<int > a,vector<int> b)
    {
        int n1 = a.size();
        int n2 = b.size();

        for(int i=0;i<n1-n2;i++)
        {
            bool ok=true;
            for(int j=0;j<n2;j++)
            {
                if(a[i+j]!=b[j])
                {
                    ok=false;
                }
            }
            if(ok)return true;
        }
        reverse(a.begin(),a.end());
        for(int i=0;i<n1-n2;i++)
        {
            bool ok=true;
            for(int j=0;j<n2;j++)
            {
                if(a[i+j]!=b[j])
                {
                    ok=false;
                }
            }
            if(ok)return true;
        }
        return false;


    }
};

double test0()
{
    int p0 = 45;
    int p1 = 4;
    TheNumberGame * obj = new TheNumberGame();
    clock_t start = clock();
    string my_answer = obj->determineOutcome(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "Manao wins";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    int p0 = 45;
    int p1 = 5;
    TheNumberGame * obj = new TheNumberGame();
    clock_t start = clock();
    string my_answer = obj->determineOutcome(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "Manao wins";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    int p0 = 99;
    int p1 = 123;
    TheNumberGame * obj = new TheNumberGame();
    clock_t start = clock();
    string my_answer = obj->determineOutcome(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "Manao loses";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    int p0 = 2356236;
    int p1 = 5666;
    TheNumberGame * obj = new TheNumberGame();
    clock_t start = clock();
    string my_answer = obj->determineOutcome(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "Manao loses";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
