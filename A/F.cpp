#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool vis[25411682];
int dp[25411682];
int T,a[5],n=71,b[5],c[2]={-1,1},d[5];
queue<int>dui;
int ans;
int final;
int main(int argc, char const *argv[])
{
    freopen("Fin.txt","r",stdin);
    scanf("%d",&T);
  //  while(T--)
      final=0;
      for(int i=1;i<=4;i++)
      {
       // scanf("%d",&a[i]);
        b[i]=i;
      }
      sort(a+1,a+5);
      for(int i=1;i<=4;i++)
        final=final*71+a[i];
      ans=999999999;
      while(!dui.empty())
        dui.pop();
      int s,t,state=0;
      state=state*71+1;
      state=state*71+2;
      state=state*71+3;
      state=state*71+4;
      dui.push(state);
      memset(dp,63,sizeof(dp));
      dp[state]=0;
      //cout<<"s= "<<state<<endl;
      memset(vis,false,sizeof(vis));
      while(!dui.empty())
      {
        s=dui.front(),dui.pop();
       // cout<<s<<endl;
        vis[s]=false;
        //if(dp[s]>=ans)
          //continue;
        int temp=s;
        for(int i=4;i>=1;i--)
        {
          b[i]=temp%71;
          temp/=71;
        }
        sort(b+1,b+1+4);
        for(int i=1;i<=4;i++)
        {
          for(int k=0;k<2;k++)
          {
            if(b[i]+c[k]>=1 && b[i]+c[k]<=70)
            {
              t=0;
              bool pd=false;
              for(int j=1;j<=4;j++)
                if(j!=i)
                  d[j]=b[j];
                else
                  d[j]=(b[j]+c[k]);
              sort(d+1,d+5);
              for(int j=1;j<=4;j++)
              {
                if(d[j]==d[j-1])
                {
                  pd=true;
                  break;
                }
                t=t*71+d[j];
              }
              if(pd)
              continue;

              if(dp[t]>dp[s]+1)
              {
                dp[t]=dp[s]+1;
             //   if(t==final)
               //   ans=min(ans,dp[t]);
                if(!vis[t])
                {
                  vis[t]=true;
                  dui.push(t);
                }
              }
            }
          }
          for(int k=1;k<=4;k++)
          {
            if(k==i)continue;
            int go=b[k]+(b[k]-b[i]);
            //if(i==2 && k==4)
           // cout<<b[i]<<" "<<b[k]<<" "<<go<<endl;
            if(go<=70 && go>=1)
            {
              t=0;
              bool pd=false;
              for(int j=1;j<=4;j++)
              {
                if(j!=i)
                  d[j]=b[j];
                else
                  d[j]=go;
              }
              sort(d+1,d+5);
              for(int j=1;j<=4;j++)
              {
                  if(d[j]==d[j-1])
                  {
                    pd=true;
                    break;
                  }
                  t=t*71+d[j];
              }
             // cout<<"t="<<t<<endl;
              if(pd)
                continue;
              if(dp[t]>dp[s]+1)
              {
                dp[t]=dp[s]+1;
              //  if(t==final)
              //    ans=min(ans,dp[t]);
                if(!vis[t])
                {
                  dui.push(t);
                  vis[t]=true;
                }
              }
            }
          }
        }
      }
    while(T--)
    {
      final=0;
      for(int i=1;i<=4;i++)
      {
        scanf("%d",&a[i]);
        b[i]=i;
      }
      sort(a+1,a+5);
      for(int i=1;i<=4;i++)
        final=final*71+a[i];
      ans=dp[final];
      printf("%d\n",ans);
    }
    return 0;
}
