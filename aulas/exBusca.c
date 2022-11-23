#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *inicializa(int n);
void BubbleSort(int *p, int ini, int fim);
int calcula_meio(int inicio, int fim);
int BuscaBinaria(int *p, int k, int ini, int fim);

int main()
{
    int *p = NULL;
    p = inicializa(10);
    BubbleSort(p, 0, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    int busca = BuscaBinaria(p, 35, 0, 10);
    printf("%d\n", busca);
}

int *inicializa(int n)
{
    int i;
    time_t t;
    int k, cont = 0;
    int *p = NULL;
    p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++, cont = cont + 10)
    {
        srand((unsigned)time(&t) + cont);
        k = rand() % 50;
        p[i] = k;
    }
    p[7] = 35;
    return p;
}

void BubbleSort(int *p, int ini, int fim)
{
    int i, j, aux;

    for (i = ini; i < fim - 1; i++)
    {

        for (j = 0; j < fim - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                // troque v[j] com v[j+1];
                aux = p[j + 1];
                p[j + 1] = p[j];
                p[j] = aux;
            }
        }
    }
}

int BuscaBinaria(int *p, int k, int ini, int fim)
{
    if (ini > fim || p == NULL)
        return 0;
    unsigned int meio = calcula_meio(ini, fim);
    if (p[meio] == k)
        return meio;
    else if (p[meio] < k)
        return BuscaBinaria(p, k, meio + 1, fim);
    else
        return BuscaBinaria(p, k, ini, meio - 1);
}

int calcula_meio(int inicio, int fim)
{
    int meio = (inicio + fim) / 2;
    return meio;
}