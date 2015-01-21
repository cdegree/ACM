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

struct Tile
{
    int no;
    char tp;
    Tile(int _no,char _tp):no(_no),tp(_tp) {}
    Tile() {}
    friend bool operator ==(Tile a,Tile b)
    {
        return a.no==b.no&&a.tp==b.tp;
    }
};
int ccnt[4][10];
int mp[256];
char typ[]= {'m','s','p','c'};
int judge3()
{
    int km=0;
    for(int i=1; i<=7; ++i)
    {
        km+=ccnt[3][i];
        if(ccnt[3][i]==0)km=-10000;
    }
    for(int i=0;i<3;++i)
    {
        km+=ccnt[i][1];km+=ccnt[i][9];
        if(ccnt[i][1]==0||ccnt[i][9]==0)km=-10000;
    }
    return km;
}

bool judge()
{
    vector<pair<int,int> > vp;
    for(int i=0; i<4; ++i)
    {
        int q = (i==3?7:9);
        for(int j=1; j<=q; ++j)
        {
            if(ccnt[i][j]>0)
            {
                vp.push_back(make_pair(i,j));
            }
        }
    }
    for(int k=0; k<vp.size(); ++k)
    {
        int i=vp[k].X;
        int j=vp[k].Y;
        if(ccnt[i][j]>=2)
        {
            int cnt[4][10];
            for(int i2=0; i2<4; ++i2)
            {
                int q = (i2==3?7:9);
                for(int j2=1; j2<=q; ++j2)
                {
                    cnt[i2][j2]=ccnt[i2][j2];
                }
            }
            cnt[i][j]-=2;
            bool ok=1;
            for(int i2=0; i2<4; ++i2)
            {
                int q = (i2==3?7:9);
                for(int j2=1; j2<=q; ++j2)
                {
                    if(cnt[i2][j2]>=3)
                    {
                        cnt[i2][j2]-=3;
                    }
                    if(q!=7)
                    while(j2+2<=q&&cnt[i2][j2+1]>0&&cnt[i2][j2+2]>0&&cnt[i2][j2]>0)
                    {
                        cnt[i2][j2+1]--,cnt[i2][j2+2]--,cnt[i2][j2]--;
                    }
                    if(cnt[i2][j2]>0)
                    {
                        ok=false;
                        break;
                    }
                }
            }

            if(ok)
            {
                return 1;
            }
        }

    }
    int ans=0;
    for(int i=0; i<4; ++i)
    {
        for(int j=1; j<=(i==3?7:9); ++j)
        {
            if(ccnt[i][j]==2)ans+=2;
        }
    }

    if(ans==14)return 1;
    if(judge3()==14)return 1;
    return false;
}
int res[1000];


int main()
{
    int T;
    //freopen("Aout.txt","w",stdout);
    scanf("%d",&T);

    mp['m']=0,mp['s']=1,mp['p']=2;
    mp['c']=3;
    while(T--)
    {
        bool ocur[4]= {0};
        memset(ccnt,0,sizeof(ccnt));
        for(int i=0; i<13; ++i)
        {
            int a;
            char s[2];
            scanf("%d%s",&a,s);
            ccnt[ mp[s[0]] ][a]++;
            ocur[ mp[s[0]] ]=1;
        }
        int len=0;
        //puts("ok");
        for(int i=0; i<4; ++i)
        {
            if(!ocur[i])continue;
            int q = (i==3?7:9);
            for(int j=1; j<=q; ++j)
            {
                if(ccnt[i][j]<4)
                {
                    ++ccnt[i][j];
                    if(judge())
                    {
                        res[len++]=j;
                        res[len++]=i;
                    }
                    --ccnt[i][j];
                }
            }
        }
        if(len==0)
        {
            puts("Nooten");
        }
        else
        {
            printf("%d",len/2);
            for(int i=0; i<len; i+=2)
            {
                printf(" %d%c",res[i],typ[res[i+1]]);
            }
            puts("");
        }
    }
    return 0;
}
