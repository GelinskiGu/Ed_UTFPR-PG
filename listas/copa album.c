#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int gastos = 0;

void figurinhas(int *p, int n);
int *comprarAlbum(int n, int *pAlbum);
void inicializar(int *p, int n);
void totalFigurinhas(int *p, int n);
int totalNaoRep(int *p, int n);
void desaloca(int **palbum);
int preencher(int *p, int n, int *p2);

int main()
{
    int op = 1, n = 670, *album = NULL, *pGastos = NULL;
    pGastos = &gastos;
    while (op)
    {
        system("cls");
        printf("\nSelecione uma opcao:");
        printf("\n0 - Para sair");
        printf("\n1 - Comprar album");
        printf("\n2 - Comprar pacote de figurinha");
        printf("\n3 - Total de figurinhas");
        printf("\n4 - Total de figurinhas nao repetidas");
        printf("\n5 - Gastos");
        printf("\n6 - Desalocar");
        printf("\n7 - Preencher figurinhas\n");
        // figurinha();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            if (album)
            {
                system("cls");
                printf("\nVoce ja comprou um album.\n");
                system("pause");
            }
            else
            {
                system("cls");
                album = comprarAlbum(n, album);
                inicializar(album, n);
                *pGastos += 12;
                printf("\nVoce comprou um album!\n");
                system("pause");
            }
        }
        break;

        case 2:
        {
            if (album == NULL)
            {
                system("cls");
                printf("\nVoce precisa ter um album.\n");
                system("pause");
            }
            else
            {
                system("cls");
                figurinhas(album, n);
                *pGastos += 4;
                printf("\n");
                system("pause");
            }
        }
        break;

        case 3:
        {
            if (album == NULL)
            {
                printf("\nVoce precisa ter um album.\n");
                system("pause");
            }
            else
            {
                system("cls");
                totalFigurinhas(album, n);
                system("pause");
            }
        }
        break;

        case 4:
        {
            if (album == NULL)
            {
                printf("\nVoce precisa ter um album.\n");
                system("pause");
            }
            else
            {
                system("cls");
                totalNaoRep(album, n);
                system("pause");
            }
        }
        break;

        case 5:
        {
            system("cls");
            printf("\nO total de dinheiro gasto foi de: R$%d,00\n", gastos);
            system("pause");
        }
        break;

        case 6:
        {
            system("cls");
            desaloca(&album);
            system("pause");
        }
        break;

        case 7:
        {
            preencher(album, n, pGastos);
        }
        break;

        case 8:
        {
            printf("\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", *(album + i));
            }
            printf("\n");
            system("pause");
        }
        }
    }
}

void figurinhas(int *p, int n)
{
    if (p)
    {
        int x, i;
        srand(time(NULL));
        for (i = 1; i <= 5; i++)
        {
            x = rand() % n; /* x vai receber um valor entre 0 e 670 */
            (*(p + x))++;
        }
    }
}

int *comprarAlbum(int n, int *pAlbum)
{
    int *p = NULL;
    if (!pAlbum)
    {
        p = (int *)malloc(sizeof(int) * n);
        if (!p)
            printf("\nMemoria insuficiente");
        return (p);
    }
    else
    {
        printf("\nVoce ja tem um album.");
        return (pAlbum);
    }
}

void inicializar(int *p, int n)
{
    for (int i = 0; i < n; i++)
        *(p + i) = 0;
}

void totalFigurinhas(int *p, int n)
{
    if (p)
    {
        int soma = 0;
        for (int i = 0; i < n; i++)
            soma += *(p + i);
        printf("\nTotal de figurinhas: %d\n", soma);
    }
}

int totalNaoRep(int *p, int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(p + i))
            soma++;
    }
    printf("\nTotal de figurinhas nao repetidas: %d\n", soma);
    return soma;
}

void desaloca(int **palbum)
{
    if (*palbum == NULL)
        printf("\nNao tem album!");
    else
    {
        free(*palbum);
        *palbum = NULL;
        printf("\nMemoria desalocada com sucesso!\n");
    }
}

int preencher(int *p, int n, int *p2)
{
    if (p)
    {
        int soma2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (*(p + i))
                soma2++;
        }
        if (soma2 < n)
        {
            Sleep(1000);
            figurinhas(p, n);
            *p2 += 4;

            //    printf("\nGastos = %d\n", gastos);
            //    system("pause");
            //   fflush(stdin);
        }
        else
        {
            printf("\nVoce completou o album\n");
            system("pause");
            return 0;
            // return *p2;
        }
        preencher(p, n, p2);
    }
    else
    {
        printf("\nVoce precisa ter um album.\n");
        system("pause");
    }
}
