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
using namespace std;

typedef long long LL ;

struct state
{
    string v[4][4];
} S;
bool vis[47];
void pf(string s)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<5;k++)
            {
                cout<<s[i*15+j*5+k];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}
string cur="";
inline int get_pos(int i,int j,int k)
{
    return i*15+j*5+k;
}

void inline gao2(int i,int j,int k,char c)
{
    //printf("%d %d %d = %c\n",i,j,k,c);
    int p,pos = i*15 + j*5 + k ;
    for( p=0; p<4; ++p)
    {
        if(p!=k&&cur[get_pos(i,j,p)]==c&&!vis[get_pos(i,j,p)])
        {
            vis[get_pos(i,j,p)]=true;
            gao2(i,j,p,c);
        }
    }
    if(k==0)
    {
        if(i>0&&cur[get_pos(i-1,j,1)]==c&&!vis[get_pos(i-1,j,1)])
        {
            vis[get_pos(i-1,j,1)]=true;
            gao2(i-1,j,1,c);
        }
    }
    else if(k==1)
    {
        if(i<2&&cur[get_pos(i+1,j,0)]==c&&!vis[get_pos(i+1,j,0)])
        {
            vis[get_pos(i+1,j,0)]=true;
            gao2(i+1,j,0,c);
        }
    }
    else if(k==2)
    {
        if(j>0&&cur[get_pos(i,j-1,3)]==c&&!vis[get_pos(i,j-1,3)])
        {
            vis[get_pos(i,j-1,3)]=true;
            gao2(i,j-1,3,c);
        }
    }
    else
    {
        if(j<2&&cur[get_pos(i,j+1,2)]==c&&!vis[get_pos(i,j+1,2)])
        {
            vis[get_pos(i,j+1,2)]=true;
            gao2(i,j+1,2,c);
        }
    }
}
inline bool OK()
{
    memset(vis,false,sizeof(vis));
    int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            for(int k=0; k<4; ++k)
            {
                int pos = i*15 + j*5 + k ;
                if(vis[pos])continue;
                vis[pos]=true;
                gao2(i,j,k,cur[pos]);
                if(cur[pos]=='R')
                {
                    ++cnt1;
                }
                else if(cur[pos]=='G')
                {
                    ++cnt2;
                }
                else if(cur[pos]=='B')
                {
                    ++cnt3;
                }
                else
                {
                    ++cnt4;
                }
                //printf("%d %d %d %d\n",cnt1,cnt2,cnt3,cnt4);
            }
        }
    }
    return cnt1<2&&cnt2<2&&cnt3<2&&cnt4<2;
}
string ret ;
inline void gao3(int pos1,int pos2)
{
    ret[pos1]=cur[pos2];
    ret[1+pos1]=cur[1+pos2];
    ret[2+pos1]=cur[2+pos2];
    ret[3+pos1]=cur[3+pos2];
    ret[4+pos1]=cur[4+pos2];
}
inline string exchang(int i1,int j1,int i2,int j2)
{
    int pos1 = i1*15+j1*5;
    int pos2 = i2*15+j2*5;
    ret = cur;

    if(i1==i2)
    {
        if(j1<j2)
        {
            gao3(pos2,pos2-5);
            gao3(pos2-5,pos2-10);
            gao3(pos2-15,pos2);
        }
        else
        {
            gao3(pos2,pos2+5);
            gao3(pos2+5,pos2+10);
            gao3(pos2+10,pos2);
        }
    }
    else
    {
        if(i1<i2)
        {
            //puts("oo");
            gao3(pos2,pos2-15);
            gao3(pos2-15,pos2-30);
            gao3(pos2-30,pos2);
            //puts("ooo");
        }
        else
        {
            //puts("oo");
            gao3(pos2,pos2+15);
            gao3(pos2+15,pos2+30);
            gao3(pos2+30,pos2);
            //puts("ooo");
        }
    }
    return ret;
}
string now;
int gao(string sta)
{
    int ret = 0 ;
    queue<string> Q;
    while(!Q.empty())Q.pop();
    map<string,int> used;
    used.clear();
    used[sta]=0;
    Q.push(sta);
    int i,j,dis;
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        dis = used[cur];
        //pf(cur);
        //printf("dis = %d\n",dis);
        if(OK())
        {
            ret = dis;
            break;
        }
        for( i=0; i<3; ++i)
        {
            //puts("ok1");
            if(cur[i*15+4]=='1'||cur[i*15+9]=='1'||cur[i*15+14]=='1')continue;
            now = exchang(i,0,i,2);
            //pf(now);
            if(used.find(now)==used.end())
            {
                used[now]=dis+1;
                Q.push(now);
            }
            now = exchang(i,2,i,0);
            if(used.find(now)==used.end())
            {
                used[now]=dis+1;
                Q.push(now);
            }
        }

        for( j=0; j<3; ++j)
        {
            //printf("ok2\n");
            if(cur[j*5+4]=='1'||cur[j*5+19]=='1'||cur[j*5+34]=='1')continue;
            now = exchang(0,j,2,j);
            //pf(now);
            if(used.find(now)==used.end())
            {
                used[now]=dis+1;
                Q.push(now);
            }
            now = exchang(2,j,0,j);
            if(used.find(now)==used.end())
            {
                used[now]=dis+1;
                Q.push(now);
            }
        }
    }
    return ret;
}
int main()
{
    int T;
    //freopen("1002in.txt","r",stdin);
    scanf("%d",&T);
    for(int t=1; t<=T; ++t)
    {
        string sta="";
        for(int i=0; i<3; ++i)
        {
            for(int j=0; j<3; ++j)
            {
                cin>>S.v[i][j];
                //cout<<S.v[i][j];
                sta+=S.v[i][j];
            }
        }
        printf("Case %d: ",t);
        int res = gao(sta);
        printf("%d\n",res);
    }
    return 0;
}
