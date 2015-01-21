#include <stdio.h>

int main()
{
    int T,i,X,Y,t,S;
    scanf("%d",&t);
    for(i=1; i<=t; ++i)
    {
        scanf("%d %d %d %d",&X,&Y,&T,&S);
        printf("Case #%d: ",i);
        if( Y>=X || T*Y + 1.0*(Y-X)/T >= S  )
        {
            printf("%.3f\n",1.0*S/X);
        }
        else
        {
            double res = 1.0*S/X;
            double pro=T*Y;
            while(pro<S)
            {
                double tmp= 1.0*pro/(X-Y);
                //printf("tmp = %.3f\n",tmp);
                if(pro+tmp*Y>=S)
                {
                    break;
                }
                pro += tmp*Y;
                res += tmp;
                //printf("res = %.3f\n",res);
                //if(tmp>=1.0*S/Y)break;
            }
            printf("%.3f\n",res);
        }
    }
}
