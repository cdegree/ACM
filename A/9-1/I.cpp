#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#define X first
#define Y second
#define sqr(x) (x)*(x)
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

char s[55][55],hole[55][55],prehole[55][55];
int T,n,m;
char knew[105][25];
set<string> kn;
struct point
{
    double x,y;
    point() {};
    point(int _x,int _y):x(_x),y(_y) {}
    void rotate(double alpha)
    {
        double rx,ry;
        rx = cos(alpha)*x - sin(alpha)*y ;
        ry = sin(alpha)*x + cos(alpha)*y ;
        x=rx;
        y=ry;
    }
    void move(double dx,double dy)
    {
        x+=dx;
        y+=dy;
    }
    void rotate_as_pointp(double dx,double dy,double alpha)
    {
        move(-dx,-dy);
        rotate(alpha);
        move(dx,dy);
    }
};

string get_reco()
{
    string ret="";
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(hole[i][j]=='*')
            {
                ret+=s[i][j]=='.'?' ':s[i][j];
            }
        }
    }
    return ret;
}
void get_hole(double alpha)
{
    double midx = 1.0*n/2;
    double midy = -midx;
    point tmp;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            tmp.x=j+0.5;
            tmp.y=-(i+0.5);
            //printf("%f,%f  ->   ",-tmp.y,tmp.x);
            tmp.rotate_as_pointp(midx,midy,alpha);
            //printf("%f,%f\n",-tmp.y,tmp.x);
            hole[ (int)(-tmp.y) ][ (int)(tmp.x) ] = prehole[i][j];;
        }
    }
}
string ans[9];

bool is_all_know(string s,string &ret)
{
    string tmp;
    tmp.clear();
    ret="";
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i]==' ')
        {
            if(!tmp.empty())
            {
                if(kn.find(tmp)==kn.end())
                {
                    return false;
                }
                ret+=tmp;
                ret+=" ";
            }
            tmp="";
        }
        else
        {
            tmp+=s[i];
        }
    }
    if(!tmp.empty())
    {
        if(kn.find(tmp)==kn.end())
        {
            return false;
        }
        ret+=tmp;
    }
    return true;
}

int main()
{
    //freopen("Iin.txt","r",stdin);
    scanf("%d",&T);
    for(int t=1; t<=T; ++t)
    {
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%s",s[i]);
        }
        for(int i=0; i<n; ++i)
        {
            scanf("%s",prehole[i]);
        }
        kn.clear();
        scanf("%d",&m);
        string tmp;
        for(int i=0; i<m; ++i)
        {
            scanf("%s",knew[i]);
            tmp= knew[i];
            kn.insert(tmp);
        }
        printf("Case #%d: ",t);
        for(int i=0; i<4; ++i)
        {
            get_hole(2*PI-i*PI/2);
            ans[i]=get_reco();
        }
        for(int i=0; i<3; ++i)
        {
            ans[i+4]=ans[i];
        }
        vector<string> res;
        for(int i=0;i<4;++i)
        {
            tmp="";
            for(int j=0;j<4;++j)
            {
                tmp+=ans[i+j];
            }
            //cout<<tmp<<endl;
            string tobe;
            if(is_all_know(tmp,tobe))
            {
                while(!tobe.empty()&&tobe[0]==' ')tobe.erase(tobe.begin());
                while(!tobe.empty()&&tobe[ tobe.size()-1 ]==' ')tobe.erase(tobe.begin()+tobe.size()-1);
                //cout<<"FFF:"<<tmp<<endl;
                res.push_back(tobe);
            }
        }
        sort(res.begin(),res.end());
        if(res.empty())
        {
            puts("FAIL TO DECRYPT");
        }
        else
        {
            cout<<res[0]<<endl;
        }

        /*
        get_hole(2*PI-PI);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                printf("%c",hole[i][j]);
            }puts("");
        }
        puts("");
        */
    }
    return 0;
}
