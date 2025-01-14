#ifndef PYTANIA_H
#define PYTANIA_H

#define MAX 100

typedef struct 
{
    char pytania[100];
    char odpowiedzi[4][100];
    char poprawna_odpowiedz;
} pytanie;

void zadajPytanie(pytanie p);


#endif