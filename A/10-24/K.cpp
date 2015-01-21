#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define ll long long
#pragma comment(linker,"/STACK:102400000,102400000")
#define FOR( i, a, b ) for(int i = a; i <= b; ++i )
const int ma=1e+9;
const int fa=1e+5+112;
int n,m;
int aa[211];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
#endif
    int i,j,k;
    while(~scanf("%d%d",&n,&m))
    {
        bool ans=false;
        if(m%2==0&&m<=n*n&&m!=2)
        {
            printf("Overwhelming power of magic\n");
            ans=true;
            int xx=0,yy=1;
            int oo=0;
            int o=m/2;
            int mm=m;
            for(int i=1; i<=n; i++)
            {
                if(mm<=n*2)
                {

                    aa[i*2]=mm/2;
                    aa[i*2-1]=mm/2;
                    oo=i*2;
                    break;
                }
                else
                {
                    mm-=2*n;
                    aa[i*2]=n;
                    aa[i*2-1]=n;
                }
            }
            xx++;
            printf("%d %d\n",xx,yy);
            xx++;
            int u=aa[oo]*2;
            if(aa[oo]*2>n)
            {
                for(int i=1; i<=oo; i++)
                {
                    if(i!=1)yy++;
                    for(j=2; j<=aa[i]; j++)
                    {
                        if(j!=2)
                        {
                            if(i%2==1)xx++;
                            else xx--;
                        }
                        printf("%d %d\n",xx,yy);
                    }
                }
            }
            else
            {
                for(int i=1; i<=oo-3; i++)
                {
                    if(i!=1)yy++;
                    for(j=2; j<=aa[i]; j++)
                    {
                        if(j!=2)
                        {
                            if(i%2==1)xx++;
                            else xx--;
                        }
                        printf("%d %d\n",xx,yy);
                    }
                }
                yy++;
                xx++;
                for(j=2; j<=aa[oo-3]; j++)
                {
                    if(xx-1>u)
                    {
                        xx--;
                        printf("%d %d\n",xx,yy);
                    }
                    else break;
                }
                int kk=0;
                for(;j<=aa[oo-3];j++)
                {
                    k++;
                    xx--;
                    if(k%2)
                    {
                        printf("%d %d\n",xx,yy);
                        printf("%d %d\n",xx,yy+1);
                    }
                    else
                    {
                        printf("%d %d\n",xx,yy+1);
                        printf("%d %d\n",xx,yy);
                    }
                }
                oo--;yy++;
            }
            xx--;
            for(int i=2; i<=oo; i++)
            {
                printf("%d %d\n",xx,yy);
                yy--;
            }
        }
        if(!ans)
        {
            printf("Unsuitable device\n");
        }
    }
    return 0;
}
