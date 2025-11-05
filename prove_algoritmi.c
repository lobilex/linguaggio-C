
#include <stdio.h>
#include <stdlib.h>


void foo(int **v)
{
    *v = (int *)malloc(10*sizeof(int));
}


main()
{
    int *v;
    foo(&v);
    v[0]=1;
    printf("value of v[0]:%d/n", v[0]);
}