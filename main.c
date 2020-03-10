#include <stdio.h>
#include "Interface.h"
int main()
{
    int i, j;
    Queue Q;
    Initialize(&Q);
    for(i = 1; i < 10; i++){
        Insert(i, &Q); 
    }

    while(!Empty(&Q))
    {
        Remove(&Q, &j);
        printf("Item %d has been removed. \n", j);
    }

    return 0;
}