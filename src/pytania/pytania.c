#include <stdio.h>
#include "pytania.h"

void zadajPytanie(pytanie q)
{
    printf("%s\n", q.pytania);
    for (int i = 0; i < 4 ; i++)
    {
        printf("%d: %s \n", i+1, q.odpowiedzi[i]);
    }
    
}