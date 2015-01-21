#include<iostream>
#include<string.h>
#include <cstdio>
#define size 100010
using namespace std;
struct Num
{
    int count;
    int prime[20];
} N[size];
__int64 elur[size];

void Elur()
{
    elur[1]=1;
    for(int i=0; i<size; i++) N[i].count=0;
    for(int i=2; i<size; i++)
    {
        if(!elur[i])    //����������
        {
            for(int j=i; j<size; j+=i)
            {
                if(!elur[j]) elur[j]=j;
                elur[j]=elur[j]*(i-1)/i; //ŷ��������ʽ
                N[j].prime[N[j].count]=i;
                N[j].count++;
            }
        }
        if(i<100)
        {
            printf("%d:\n",i);
            for(int j=0; j<N[i].count; ++j)
            {
                printf("%d ",N[i].prime[j]);
            }
            puts("");
        }
        elur[i]+=elur[i-1];  //elur[i]��ʾǰi���������������ۼӡ�
        //if(i<50)printf("%lld\n",elur[i]);
    }
}

__int64 Inclusion_exclusion(int index , int b , int n)
{
    //index��ʾ�˿��㵽�ĸ���������b��ʾ��1~b�м��㱻�����������ĸ�����ָ�ڶ����������һ������
    __int64 r=0 , t;
    for(int i=index; i<N[n].count; i++) //x��y�����Լ��Ϊk*p(pΪ����)
    {
        printf("%d\n",N[n].prime[i]);
        t=b/N[n].prime[i];
        r+=t-Inclusion_exclusion(i+1,t , n);  //��Ϊ��ֹ�������ظ����㣬���Ը����ݳⶨ��
    }
    //cout<<r<<endl;
    return r;
}
int main()
{
    int a , b, c, d , k;
    int t ,tt=0;
    Elur();
    __int64 ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0)
        {
            printf("Case %d: 0\n",++tt);
            continue;
        }
        if(b>d)
        {
            b^=d;
            d^=b;
            b^=d;
        }
        b=b/k;
        d=d/k;
        ans=elur[b];
        for(int i=b+1; i<=d; i++)
        {
            ans+=b-Inclusion_exclusion(0,b,i);
        }
        printf("Case %d: %I64d\n",++tt,ans);
    }
    return 0;
}
