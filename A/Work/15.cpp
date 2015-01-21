#include <cstdio>

int inc(int a)
{
    return (++a);
}

int multi(int *a,int *b,int *c)
{
    return (*c=*a**b);
}
typedef int(FUNC1)(int inc);
typedef int(FUNC2) (int*,int*,int*);

void show(FUNC2 fun,int arg1,int *arg2)
{
    FUNC1 *p = &inc;
    int tmp = p(arg1);
    fun(&tmp,&arg1,arg2);
    printf("0x%x\n",*arg2);
}

int main()
{
    int a;
    show(multi,9,&a);
	return 0;
}
