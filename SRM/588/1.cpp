
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

int dp[55][55][55];
struct song
{
    int dur;
    int tn;
}S[55];
bool cmp(song a,song b)
{
    return a.tn<b.tn;
}
class GUMIAndSongsDiv1
{
public:
    int maxSongs(vector <int> duration, vector <int> tone, int T)
    {
        int n =duration .size();
        for(int i=0;i<n;++i)
        {
            S[i+1].dur=duration[i];
            S[i+1].tn=tone[i];
        }
        sort(S+1,S+n+1,cmp);
        for(int i=0; i<=n; ++i)for(int j=0; j<=n; ++j)for(int k=0; k<=n; ++k)dp[i][j][k]=1e8;
        dp[0][0][0]=0;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=i; ++j)
            {
                dp[i][j][1]=min(dp[i][j][1],S[j].dur);
                for(int k=0; k<=i; ++k)
                {
                    for(int j2=1; j2<j; ++j2)
                    {
                        dp[i][j][k+1]=min(dp[i][j][k+1],dp[i-1][j2][k]+S[j].dur+abs(S[j].tn-S[j2].tn));
                    }
                }
            }
        }
        if(n<10)
            for(int i=0; i<=n; ++i)
            {
                printf("%d:\n",i);
                for(int j=0; j<=n; ++j)
                {
                    for(int k=0; k<=n; ++k)
                                        {
                        printf("%d ",dp[i][j][k]);
                    }
                    puts("");
                }
                puts("");
            }
        int res=0;
        for(int i=1; i<=n; ++i)
        {
            for(int j=0; j<=n; ++j)
            {
                if(dp[n][i][j]<=T)
                {
                    res=max(res,j);
                }
            }
        }
        return res;
    }
};

double test0()
{
    int t0[] = {3, 5, 4, 11};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {2, 1, 3, 1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int p2 = 17;
    GUMIAndSongsDiv1 * obj = new GUMIAndSongsDiv1();
    clock_t start = clock();
    int my_answer = obj->maxSongs(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 3;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    int t0[] = {100, 200, 300};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1, 2, 3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int p2 = 99;
    GUMIAndSongsDiv1 * obj = new GUMIAndSongsDiv1();
    clock_t start = clock();
    int my_answer = obj->maxSongs(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    int t0[] = {1, 2, 3, 4};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1, 1, 1, 1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int p2 = 100;
    GUMIAndSongsDiv1 * obj = new GUMIAndSongsDiv1();
    clock_t start = clock();
    int my_answer = obj->maxSongs(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 4;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    int t0[] = {9, 11, 13, 17};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {2, 1, 3, 4};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int p2 = 20;
    GUMIAndSongsDiv1 * obj = new GUMIAndSongsDiv1();
    clock_t start = clock();
    int my_answer = obj->maxSongs(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    int t0[] = {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,
                67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97
               };
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,
                61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3
               };
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int p2 = 212;
    GUMIAndSongsDiv1 * obj = new GUMIAndSongsDiv1();
    clock_t start = clock();
    int my_answer = obj->maxSongs(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 12;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}


//Powered by [KawigiEdit] 2.0!
