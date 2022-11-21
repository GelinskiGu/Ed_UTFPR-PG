#include <stdio.h>
#include <stdlib.h>
#define tam 10

void imprime(float *p);

int main()
{
    float *p = NULL;
    p = (float *)malloc(sizeof(float) * tam);
    imprime(p);
}

void imprime(float *p)
{
    if (p)
        for (int i = 0; i < tam; i++)
            printf("%p\n", *(p + i));
}