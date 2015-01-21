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
int Set[55];
int Find_Set(int x)
{
    if(x==Set[x])return x;
    return Set[x]=Find_Set(Set[x]);
}
void Union_Set(int x,int y)
{
    Set[Find_Set(y)]=Find_Set(x);
}
bool vis[55][55];
class GooseTattarrattatDiv1
{
public:
    int getmin(string S)
    {
        int n = S.size();
        int cnt[27]= {0};
        for(int i=0; i<n; ++i)
        {
            cnt[ S[i]-'a' ]++;
        }
        vector<int> st[27];
        for(int i=0; i<26; ++i)
        {
            st[i].push_back(cnt[i]);
            Set[i]=i;
        }

        for(int i=0; i<n/2; ++i)
        {
            if(S[i]!=S[n-i-1])
            {
                int x = Find_Set(S[i]-'a');
                int y = Find_Set(S[n-i-1]-'a');
                if(x==y)continue;
                for(int j=0;j<st[y].size();++j)st[x].push_back(st[y][j]);
                st[y].clear();
                Union_Set(x,y);
            }
        }
        int res=0;
        for(int i=0;i<26;++i)
        {
            if(st[i].empty())continue;
            sort(st[i].begin(),st[i].end());
            //printf("%c:",i+'a');
            for(int j=0;j<st[i].size()-1;++j)
            {
                //printf("%d  ",st[i][j]);
                res+=st[i][j];
            }
            //puts("");
        }
        return res;
    }
};

double test0()
{
    string p0 = "geese";
    GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
    clock_t start = clock();
    int my_answer = obj->getmin(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
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
    string p0 = "tattarrattat";
    GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
    clock_t start = clock();
    int my_answer = obj->getmin(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
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
    string p0 = "xyyzzzxxx";
    GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
    clock_t start = clock();
    int my_answer = obj->getmin(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
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
    string p0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
    GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
    clock_t start = clock();
    int my_answer = obj->getmin(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 11;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
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
    string p0 = "abaabb";
    GooseTattarrattatDiv1 * obj = new GooseTattarrattatDiv1();
    clock_t start = clock();
    int my_answer = obj->getmin(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 3;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
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
