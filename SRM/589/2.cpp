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
const int N=55;
int uN,vN;//u,v数目
int link[N];
bool used[N];
int g[N][N];
bool dfs(int u)//从左边开始找增广路径
{
    int v;
    for(v=0; v<vN; v++) //这个顶点编号从0开始，若要从1开始需要修改
    {
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(link[v]==-1||dfs(link[v]))
            {
                //找增广路，反向
                link[v]=u;
                return true;
            }
        }
    }
    return false;//这个不要忘了，经常忘记这句
}
int bimatch(int n)
{
    uN=vN=n;
    int res=0;
    int u;
    memset(link,-1,sizeof(link));
    for(u=0; u<uN; u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}

int mp[256];

int get_ans(string c,vector<string> gra)
{
    int n = c.size();
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(gra[i][j]=='Y'&& mp[ c[i] ]== mp[ c[j] ])
            {
                g[i][j]=1;
            }
            else g[i][j]=0;
        }
    }
    return bimatch(n)/2;
}

class GearsDiv1
{
public:
    int getmin(string color, vector <string> graph)
    {
        int res;
        mp['R']=0,mp['G']=1,mp['B']=1;
        res = get_ans(color,graph);
        mp['R']=0,mp['G']=0,mp['B']=1;
        res = min(res, get_ans(color,graph));
        mp['R']=0,mp['G']=1,mp['B']=0;
        res = min(res, get_ans(color,graph));
        return res;
    }
};
//Powered by [KawigiEdit] 2.0!

double test0()
{
    string p0 = "RGB";
    string t1[] = {"NYY","YNY","YYN"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GearsDiv1 * obj = new GearsDiv1();
    clock_t start = clock();
    int my_answer = obj->getmin(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 1;
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
    string p0 = "RGBR";
    string t1[] = {"NNNN","NNNN","NNNN","NNNN"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GearsDiv1 * obj = new GearsDiv1();
    clock_t start = clock();
    int my_answer = obj->getmin(p0, p1);
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
double test2()
{
    string p0 = "RGBR";
    string t1[] = {"NYNN","YNYN","NYNY","NNYN"};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GearsDiv1 * obj = new GearsDiv1();
    clock_t start = clock();
    int my_answer = obj->getmin(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 1;
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
    string p0 = "RRRRRGRRBGRRGBBGGGBRRRGBRGRRGG";
    string t1[] = {"NNNNNYNNNYNNYNNNYNNNNNNNNYNNYY",
                   "NNNNNNNNYNNNYNYNNYNNNNYNNYNNYY",
                   "NNNNNYNNNNNNNNNNNNYNNNNNNYNNNY",
                   "NNNNNNNNNYNNYNNYYYNNNNYNNYNNNN",
                   "NNNNNNNNNYNNYNNYYYNNNNYNNNNNNN",
                   "YNYNNNYYYNNYNYYNNNNNYYNYNNYYNN",
                   "NNNNNYNNNNNNNNNYYYNNNNYNNYNNYY",
                   "NNNNNYNNNNNNNNNYNNNNNNNNNNNNYN",
                   "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
                   "YNNYYNNNYNNNNYYNNNYNYYNYNNNNNN",
                   "NNNNNNNNNNNNYNNYNYNNNNYNNNNNNY",
                   "NNNNNYNNNNNNYNNYYYNNNNNNNNNNYN",
                   "YYNYYNNNYNYYNYYNNNYNYNNYNNNNNN",
                   "NNNNNYNNNYNNYNNYYYNNNNYNNYNYYY",
                   "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
                   "NNNYYNYYYNYYNYYNNNYNYNNYYNYYNN",
                   "YNNYYNYNYNNYNYYNNNYNNNNYYNNYNN",
                   "NYNYYNYNYNYYNYYNNNNYYNNYYNYNNN",
                   "NNYNNNNNNYNNYNNYYNNNNNYNNYNNNY",
                   "NNNNNNNNNNNNNNNNNYNNNNYNNYNNNY",
                   "NNNNNYNNNYNNYNNYNYNNNNYNNNNNYY",
                   "NNNNNYNNNYNNNNNNNNNNNNYNNNNNNN",
                   "NYNYYNYNYNYNNYYNNNYYYYNYYNYNNN",
                   "NNNNNYNNNYNNYNNYYYNNNNYNNNNNNY",
                   "NNNNNNNNNNNNNNNYYYNNNNYNNYNNYY",
                   "YYYYNNYNYNNNNYYNNNYYNNNNYNYYNN",
                   "NNNNNYNNNNNNNNNYNYNNNNYNNYNNYN",
                   "NNNNNYNNNNNNNYNYYNNNNNNNNYNNYY",
                   "YYNNNNYYYNNYNYYNNNNNYNNNYNYYNN",
                   "YYYNNNYNYNYNNYYNNNYYYNNYYNNYNN"
                  };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GearsDiv1 * obj = new GearsDiv1();
    clock_t start = clock();
    int my_answer = obj->getmin(p0, p1);
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
