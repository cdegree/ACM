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
typedef long long LL;
vector<int> p;
LL n;
bool vis[22];
vector<pair<int,int> >sp;
LL dp[22][(1<<19)];
class PolygonTraversal
{
public:
    long long count(int N, vector <int> points)
    {
        n = N;
        p = points;
        int m = p.size();
        if(m==2)return 0;
        sp.clear();
        for(int i=0;i<n;i++)vis[i]=false;
        for(int i=0;i<m;i++)
        {
            --p[i];
            vis[p[i]]=true;
        }
        for(int i=0;i<m-1;i++)
        {
            sp.push_back(make_pair(p[i],p[i+1]));
        }
        int mask = 0;
        for(int i=0;i<m;i++)
        {
            mask|=(1<<p[i]);
        }
        memset(dp,-1,sizeof(dp));
        vis[p[0] ]=false;
        LL res = gao(p[m-1],mask,m,sp);
        return res;
    }
    inline int count(int mask)
    {
        int ret=0;
        for(int i=0;i<n;i++)
        {
            ret += ((mask&(1<<i))!=0);
        }
        return ret;
    }
    LL gao(int cur,int mask,int cnt,vector<pair<int,int> > vp)
    {
        LL &ret = dp[cur][mask];
        //printf("cur = %d\n",cur);
        if(ret!=-1)return ret;
        ret=0;
        if(cnt==n&&cur==p[0])return ret =1;
        if(cur==p[0])return 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && ( check2(i,cur) ) &&ok(cur,i,vp))
            {
                vis[i]=true;
                vector<pair<int,int> > nvp = vp;
                nvp.push_back( make_pair(cur,i));
                ret += gao(i,mask|(1<<i),cnt+1,nvp);
                vis[i]=false;
            }
        }
        return ret;
    }
    bool check2(int a,int b)
    {
        if(a>b)swap(a,b);
        if(b-a<=1||(b==n-1&&a==0))return false;
        return true;
    }
    bool ok(int cur,int des,vector<pair<int,int> > vp)
    {
        for(int i=0;i<vp.size();i++)
        {
            if(check(cur,des,vp[i].first,vp[i].second)||check(des,cur,vp[i].first,vp[i].second))return true;
        }
        return false;
    }
    inline bool check(int cur,int des,int a,int b)
    {
        if(a>b)swap(a,b);
        return ( a<cur&&cur<b )||( des<a||des>b );
    }
};

double test0()
{
    int p0 = 5;
    int t1[] = {1, 3, 5};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    PolygonTraversal * obj = new PolygonTraversal();
    clock_t start = clock();
    long long my_answer = obj->count(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 1LL;
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
    int p0 = 6;
    int t1[] = {1, 4, 2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    PolygonTraversal * obj = new PolygonTraversal();
    clock_t start = clock();
    long long my_answer = obj->count(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 1LL;
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
    int p0 = 7;
    int t1[] = {2, 4, 7};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    PolygonTraversal * obj = new PolygonTraversal();
    clock_t start = clock();
    long long my_answer = obj->count(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 2LL;
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
    int p0 = 7;
    int t1[] = {1, 2, 3, 4, 6, 5};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    PolygonTraversal * obj = new PolygonTraversal();
    clock_t start = clock();
    long long my_answer = obj->count(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 0LL;
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
    int p0 = 18;
    int t1[] = {1, 7, 18};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    PolygonTraversal * obj = new PolygonTraversal();
    clock_t start = clock();
    long long my_answer = obj->count(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p2 = 4374612736LL;
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}


//Powered by [KawigiEdit] 2.0!
