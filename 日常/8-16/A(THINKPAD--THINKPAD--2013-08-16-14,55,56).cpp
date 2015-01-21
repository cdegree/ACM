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
const int N = 100005;
char s1[N],s2[N];
int res[N];
char s3[N];
int next[N];
int p[N];
int tmpres[N];
int tmplen=0;
int
 OK(char *a,int n,char *b,int m)
{
    p[0]=-1;
    int i,j=-1;
    for(i=1; i<=m; i++)
    {
        while((j>0)&&(b[j+1]!=b[i]))
            j=p[j];
        if(b[j+1]==b[i]) j++;
        p[i]=j;
    }
    //for(i=0;i<m;i++) printf("%d   ",p[i]); printf("\n");
    j=-1;
    for(i=0; i<n; i++)
    {
        while((j>0)&&(b[j+1]!=a[i])) j=p[j];
        if(b[j+1]==a[i])
        {
            j++;
        }
        if(j==m-1)
        {
            return i-m+1;
            j=p[j];
        }
    }
    return -1;
}
char tmp[N];
char tmp2[N];
int main()
{
// s1[]="abcd";
    //char s2[]="d";
    //printf("%d\n",OK(s1,4,s2,1));
    while(gets(s1))
    {
        if(s1[0]=='\n')continue;
        while(gets(s2))if(s2[0]=='\n')continue;
            else break;

        int n=strlen(s1);
        int m=strlen(s2);
        int i,j=0;
        int len=0,reslen=0;
        bool enable_b=false;
        bool ok=0;
        strcpy(s3,s1);
        len=0;
        int len2=0;
        reslen=0;
        for(i=0,j=0; i<=m; ++i)
        {
            if(s2[i]==' '||s2[i]=='\0')
            {
                tmp[len]='\0';
                printf("tmp=%s\n",tmp);
                ok=false;
                while(!ok)
                {
                    len2=0;
                    printf("j=%d\n",j);
                    if(j>n)break;
                    int nj=j;
                    for(; s1[j]!=' '&&s1[j]!='\0'; ++j)
                    {
                        tmp2[len2++]=s1[j];
                    }
                    tmp2[len2]='\0';
                    printf("len2=%d\n",len2);
                    printf("tmp2=%s\n",tmp2);
                    if(len2>=len)
                    {
                        int kl = OK(tmp2,len2,tmp,len);
                        printf("kl = %d\n",kl);
                        if( ~kl )
                        {
                            for(int k=nj+kl;k<nj+kl+len;++k)
                            {
                                res[reslen++]=s2[k];
                            }
                            ok=1;
                        }
                    }
                    ++j;
                }
                len=0;
                printf("ok=%d\n",ok);
                if(!ok)break;
            }
            else
            {
                tmp[len++]=s2[i];
            }
        }
        printf("i=%d\n",i);
        ok=0;
        if(i==m+1)ok=1;
        len=m;
        for(int i=0; i<n; ++i)if(s3[i]!=' ')s3[i]='_';
        for(int i=0; i<len; ++i)
        {
            printf(" res[%d]=%d\n",i,res[i]);
            s3[ res[i] ] = s1[ res[i] ];
        }
        //printf("%s\n",s1);
        if(ok)
        {
            printf("%s\n",s3);
        }
        else
        {
            puts("I HAVE FAILED!!!");
        }
    }
    return 0;
}
