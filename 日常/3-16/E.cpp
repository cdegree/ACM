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

using namespace std;

typedef long long LL ;

LL Ngcd(vector<LL> a)
{
    int n=a.size();
    LL ret = a[0];
    for(int i=1; i<n; i++)
    {
        ret = __gcd(ret,a[i]);
    }
    return ret;
}

struct Mat
{
    LL a[3][3];
    LL b[3];
    void Mswap(int r1,int r2)
    {
        for(int i=0; i<3; i++)
        {
            swap(a[r1][i],a[r2][i]);
        }
        swap(b[r1],b[r2]);
    }
    void discard(int r1,int r2,int col)
    {
        vector<LL> vl;
        if(a[r2][col]==0)return ;
        LL lmd = 1;
        if(a[r1][col]!=0)lmd*=a[r1][col],vl.push_back(a[r1][col]);
        if(a[r2][col]!=0)lmd*=a[r2][col],vl.push_back(a[r2][col]);
        LL gg = Ngcd(vl);
        lmd /= gg;
        //printf("lmd = %lld\n",lmd);
        LL ex1 ;
        if(a[r1][col]!=0) ex1 = lmd/a[r1][col];
        LL ex2 ;
        if(a[r2][col]!=0) ex2=  lmd/a[r2][col];

        for(int i=col; i<3; i++)
        {
            a[r2][i] *= ex2;
            a[r1][i] *= ex1;
            //printf("%lld - %lld\n",a[r2][i],a[r1][i]);
            a[r2][i] -= a[r1][i];
        }
        b[r2] *= ex2;
        b[r1] *= ex1;
        b[r2] -= b[r1];
        adjust(r1);
        adjust(r2);
    }
    void adjust(int row)
    {
        vector<LL> vl;
        for(int i=0;i<3;i++)
        {
            if(a[row][i]<0)
            {
                for(int j=0;j<3;j++)a[row][j]*=-1;
                break;
            }
        }
        for(int i=0; i<3; i++)
        {
            if(a[row][i]!=0)
            {
                vl.push_back(a[row][i]);
            }
        }
        if(b[row]!=0) vl.push_back(b[row]);
        if(vl.size()>0)
        {
            LL gg = Ngcd(vl);
            for(int i=0; i<3; i++)
            {
                a[row][i] /= gg;
            }
            b[row] /= gg;
        }
    }
};
Mat mat;
void print()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%10lld  ",mat.a[i][j]);
        }
        printf("%10lld\n",mat.b[i]);
    }
    puts("");
}

const double eps = 1e-8;
bool gao()
{
    int i,j;
    for(i=0,j=0; i<3&&j<3; i++,j++)
    {
        int k = i ;
        //printf("%d %d\n",i,j);
        while(  k<3 && mat.a[k][j]==0 ) k++;
        if(k==3)
        {
            i--;
            //printf("no\n");
            continue;
        }
        //printf(" k = %d %d\n",k,i);
        mat.Mswap(k,i);
        //print();
        for(int v=0; v<3; v++)
        {
            if(v==i)continue;
            mat.discard(i,v,j);
        }
        //print();
        //printf("ok 1 time\n");
        //printf("%lf \n",mat.a[i][0]);
    }
    for(int i=0; i<3; i++)
    {
        bool have = false;
        for(int j=0; j<3; j++)
        {
            if(mat.a[i][j]>0)
            {
                have=true;
            }
        }
        if(  (have&&mat.b[i]==0)||(!have&&mat.b[i]>0) )
        {
            return false;
        }
        if(mat.b[i]<0)return false;
    }
    return true;
}
int main()
{
    //freopen("Ein.txt","r",stdin);
    while(~scanf("%lld %lld %lld",&mat.a[0][0],&mat.a[1][0],&mat.a[2][0]))
    {
        if(mat.a[0][0]==0&&mat.a[1][0]==0&&mat.a[2][0]==0)break;
        for(int j=1; j<3; j++)
        {
            for(int i=0; i<3; i++)
            {
                scanf("%lld",&mat.a[i][j]);
            }
        }
        for(int i=0; i<3; i++)scanf("%lld",&mat.b[i]);

        //print();
        if(gao())
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
        //print();
    }
    return 0;
}
