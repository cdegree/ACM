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
vector<string> gg;
vector<int> bb;
int n,ccnt;
string ret;
bool have[55][11];
bool too;
int m;
class EllysBulls
{
public:
    string getNumber(vector <string> g, vector <int> b)
    {
        n = b.size();
        m=g[0].size();
        bb=b;
        gg=g;
        for(int i=0; i<n; i++)for(int j=0; j<10; j++)have[i][j]=true;
        for(int i=0; i<n; i++)
        {
            if(b[i]==0)
            {
                for(int j=0; j<m; j++)have[i][ g[i][j]-'0' ]=false;
            }
        }
        ccnt=0;
        ret="";
        printf("ok1\n");
        too=false;
        gao(0,"");
        if(too)ret="Ambiguity";
        else if(ccnt==0)ret="Liar";
        return ret;
    }
    void gao(int cur,string now)
    {
        if(too)return ;
        if(cur==m)
        {
            //cout<<now<<endl;
            bool ok=true;
            for(int i=0; i<n; i++)
            {
                if(count(gg[i],now)!=bb[i])
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                ccnt++;
                if(ccnt==2)
                {
                    too=true;
                    return ;
                }
                ret = now;
            }
            return ;
        }
        else
        {
            bool ok=true;
            for(int i=0; i<n; i++)
            {
                if(count(gg[i],now)>bb[i])
                {
                    ok=false;
                    break;
                }
            }
            if(!ok)
            {
                //if(m==7)cout<<now<<endl;
                return ;
            }
        }
        for(int i=0; i<10; i++)
        {
            if(!have[cur][i])continue;
            //cout<<s<<endl;
            char c = '0'+i;
            //cout<<s<<endl;
            gao(cur+1,now+c);
            if(too)return ;
        }
    }
    inline int count(string a,string b)
    {
        int cnt=0;
        for(int i=0; i<b.size(); i++)
        {
            cnt+=a[i]==b[i];
        }
        return cnt;
    }
};

double test0()
{
    string t0[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int t1[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    EllysBulls * obj = new EllysBulls();
    clock_t start = clock();
    string my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "1337";
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
    string t0[] = {"0000", "1111", "2222"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int t1[] = {2, 2, 2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    EllysBulls * obj = new EllysBulls();
    clock_t start = clock();
    string my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "Liar";
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
    string t0[] = {"666666", "666677", "777777", "999999"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int t1[] = {2, 3, 1, 0};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    EllysBulls * obj = new EllysBulls();
    clock_t start = clock();
    string my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "Ambiguity";
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
    string t0[] = {"000", "987", "654", "321", "100", "010"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int t1[] = {2, 1, 0, 0, 1, 1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    EllysBulls * obj = new EllysBulls();
    clock_t start = clock();
    string my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "007";
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
double test4()
{
    string t0[] = {"28", "92", "70", "30", "67", "63", "06", "65",
                   "11", "06", "88", "48", "09", "65", "48", "08"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int t1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    EllysBulls * obj = new EllysBulls();
    clock_t start = clock();
    string my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "54";
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
double test5()
{
    string t0[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
                   "4166623", "1166638", "2767693", "8650248", "2486509",
                   "6138934", "4018642", "6236742", "2961643", "8407361",
                   "2097376", "6575410", "6071777", "3569948", "2606380"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int t1[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    EllysBulls * obj = new EllysBulls();
    clock_t start = clock();
    string my_answer = obj->getNumber(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "4266642";
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
