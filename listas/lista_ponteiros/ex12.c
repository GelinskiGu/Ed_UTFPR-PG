#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *aloca(int n);
void armazena(int *p, int n);

void main()
{
    int *pa = NULL, *pb = NULL, *pc = NULL, nA, nB;

    printf("Tamanho de A:\n");
    scanf("%d", &nA);
    printf("Tamanho de B:\n");
    scanf("%d", &nB);
    pa = aloca(nA);
    pb = aloca(nB);
    printf("Valores para o vetor A:\n");
    armazena(pa, nA);
    printf("Valores para o vetor B:\n");
    armazena(pb, nB);
}

int *aloca(int n)
{
    int *p = NULL;
    p = (int *)malloc(sizeof(int) * n);
    if (p == NULL)
        printf("SO nao liberou memoria!\n");
    return p;
}

void armazena(int *p, int n)
{
    if (p == NULL)
    {
        printf("Erro.\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        printf("\tDigite o valor [%d]:\n\t", i + 1);
        scanf("%d", (p + i));
    }
}