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
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef long long LL ;

int main(int argc, char const *argv[])
{
	double L,P;
	double h1 = 0.117, h2 = 0.293, h3 = 0.117;
	double g1 = 0.142, g2 = 0.094, g3 = 0.047;
	double D1 = 0.473, D2 = 0.717 ;

	double K = D1*D2 + h1*g1 + h2*g2 + h3*g3 + (h1+h2+h3)*D2 + (g1+g2+g3)*D1;

	double M_h1 = ( h1*g1 + h1*D2 + D1*g1 ) / K;
	double M_h2 = ( h2*g2 + h2*D2 + D1*g2 ) / K;
	double M_h3 = ( h3*g3 + h3*D2 + D1*g3 ) / K;

	printf("K = %.3f\n", K   );
	printf("M_h1 = %.3f\n",M_h1);
	printf("M_h2 = %.3f\n",M_h2);
	printf("M_h3 = %.3f\n",M_h3);

	double Bel_H = M_h1 + M_h2 + M_h3;
	printf("Bel_H = %.3f\n",Bel_H);

	double f_H = Bel_H + ( 1 - Bel_H )*3/10 ;
	printf("f_H = %.3f\n",f_H);
	/*
	//freopen("Ain.txt","r",stdin);
	while(cin>>L>>P)
	{
		printf("res = %.3f\n",L*P/((L-1)*P+1));
	}
	*/
	return 0;
}