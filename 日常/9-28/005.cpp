#include<stdio.h>
#include<string.h>
#include<algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
using namespace std ;

const int maxn = 1111111 ;

int max ( int a , int b ) { return a > b ? a : b ; }

int p[maxn] ;

void get_p (const char *T){
     int len=strlen(T),a=0;
     int i , k ;
     p[0]=len;
     while(a<len-1 && T[a]==T[a+1]) a++;
     p[1]=a;
     a=1;
     for( k=2;k<len;k++){
         int fuck=a+p[a]-1,L=p[k-a];
         if( (k-1)+L >= fuck){
             int j = (fuck-k+1)>0 ? (fuck-k+1) : 0;
             while(k+j<len && T[k+j]==T[j]) j++;
             p[k]=j;
             a=k;
         }
         else p[k]=L;
     }
}

char s[maxn] ;

int main () {
    int t , i ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        scanf ( "%s" , s ) ;
        get_p ( s ) ;
        int n = strlen ( s ) ;

        for(i = 0; i < n; ++i) {
            printf("%3c", s[i]);
        } puts("");
        for( i = 0; i < n; ++i) {
            printf("%3d", p[i]);
        } puts("");

        int mx = 0 ;
        int ans = 0 ;
        for ( i = n / 3 ; i <= n - 2 * ( n / 3 ) ; i ++ ) mx = max ( mx , p[i] ) ;
        int l = n / 3 , r = n - 2 * ( n / 3 ) ;
    //    printf ( "l = %d , r = %d\n" , l , r ) ;
        for ( i = n / 3 ; i >= 1 ; i -- ) {
      //      printf ( "p[%d] = %d , mx = %d\n" , n - i , p[n-i] , mx ) ;
            if ( p[n-i] == i && mx >= i ) {
                ans = i ;
                break ;
            }
     //       printf ( "l = %d , r = %d " , l , r ) ;
            mx = max ( mx , max ( p[--l] , p[++r] ) ) ;
            mx = max ( mx , p[++r] ) ;
 //           printf ( "mx = %d\n" , mx ) ;
        }
        printf ( "%d\n" , ans ) ;
    }
    return 0 ;
}
