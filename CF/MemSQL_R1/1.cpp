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

struct rect
{
    int x0,y0,x1,y1;
}R[6];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        LL sumS=0;
        int lx=55555,ly=55555,rx=-1,ry=-1;
        for(int i=0;i<n;++i)
        {
            scanf("%d %d %d %d",&R[i].x0,&R[i].y0,&R[i].x1,&R[i].y1);
            sumS += (R[i].y1-R[i].y0)*(R[i].x1-R[i].x0);
            lx=min(lx,R[i].x0);
            ly=min(ly,R[i].y0);
            rx=max(rx,R[i].x1);
            ry=max(ry,R[i].y1);
        }
        if((LL)(rx-lx)*(ry-ly)==sumS&&(rx-lx)==(ry-ly))
        {
            cout<<"YES";
        }
        else cout<<"NO";
        cout<<endl;

    }
	return 0;
}
