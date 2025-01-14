#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wylosujPytanie.h"

int wylosujPytanie()
{
    srand(time(NULL));
    int nr_pytania = (rand()%100)+1;
    return nr_pytania;
}