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
int n;
char s[100005];
int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%s",s);

        bool found=false;
        for(int i=0; i<n; ++i)
        {
            if(s[i]!='0')
            {
                found=true;
                break;
            }
        }
        int ret;
        if(!found)
        {
            ret=n%2;
        }
        else
        {
            ret=0;
            int pre=-1,fir,las;
            for(int i=0; i<n; ++i)
            {
                if(s[i]!='0')
                {
                    if(pre==-1)
                    {
                        fir=i;
                    }
                    else if(i-pre>1)
                    {
                        int len;
                        if(s[pre]==s[i])
                        {
                            ret+=1;
                        }
                        else
                        {
                            ret+=2;
                        }
                        //printf("%d -> %d : %d\n",pre,i,i-pre-1);
                    }
                    pre=i;
                }
            }
            las=n-pre-1;
            int b=0;
            if(fir>1)
            {
                ++b;
            }
            else if(fir==1)
            {
                ret+=1;
            }

            if(las>1)
            {
                ++b;
            }
            else if(las==1)
            {
                ret+=1;
            }
            if(b==1)
            {
                ret=1;
            }
            else if(b==2)
            {
                if(abs(fir-las)==1&&min(fir,las)%2==0)
                {
                    ++ret;
                }
                else if(fir==las)
                {

                }
                else
                {
                    ret=1;
                }
            }
            //printf("cnt=  %d\n",cnt);
            //printf("cnt=  %d\n",cnt);
        }
        printf("%s\n",(ret%2==1)?"FIRST":"SECOND");
    }

    return 0;
}
