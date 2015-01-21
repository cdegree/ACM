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

char mp[256];

struct rabbit
{
    char dir[2];
    int x,y,s,k;
    int t;
} R[2];

int dx[]= {0,-1,0,1};
int dy[]= {1,0,-1,0};

void init()
{
    mp['E']=0;
    mp['S']=1;
    mp['W']=2;
    mp['N']=3;
}
int n;

void get_next(rabbit &r)
{
    int &k = r.k;
    //printf("%d , %d\n",r.x,r.y);
    for(int i=0; i<r.s; ++i)
    {
        //printf("k=%d\n",k);
        int ddx = dx[k];
        int ddy = dy[k];
        int nx = ddx+r.x;
        int ny = ddy+r.y;
        if(nx<1)
        {
            nx=2;
            k=(k+2)%4;
        }
        else if(nx>n)
        {
            nx = n-1;
            k=(k+2)%4;
        }
        else if(ny<1)
        {
            ny=2;
            k=(k+2)%4;
        }
        else if(ny>n)
        {
            ny=n-1;
            k=(k+2)%4;
        }
        r.x=nx,r.y=ny;
        //printf("%d,%d\n",r.x,r.y);
    }
}
int main()
{

    init();
    while(1)
    {
        cin>>n;
        if(n==0)break;
        for(int i=0; i<2; ++i)
        {
            scanf("%s%d%d",R[i].dir,&R[i].s,&R[i].t);
            R[i].k=mp[ R[i].dir[0] ];
            //printf("k=%d\n",R[i].k);
        }
        int k;
        scanf("%d",&k);
        R[0].x=1,R[0].y=1;
        R[1].x=n,R[1].y=n;
        for(int i=0; i<k; ++i)
        {
            if(R[0].x==R[1].x&&R[0].y==R[1].y)
            {
                swap(R[0].k,R[1].k);
            }
            else if(i>0&&(i%R[0].t==0||i%R[1].t==0))
            {
                if(i%R[0].t==0)
                {
                    R[0].k=(R[0].k+1)%4;
                }
                if(i%R[1].t==0)
                {
                    R[1].k=(R[1].k+1)%4;
                }
            }
            get_next(R[0]);
            get_next(R[1]);
        }
        for(int i=0;i<2;++i)
        {
            printf("%d %d\n",R[i].x,R[i].y);
        }
    }
    return 0;
}
