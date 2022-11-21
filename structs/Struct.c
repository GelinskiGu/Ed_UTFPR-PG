#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[50];
    int ra;
    int idade;
} TipoAluno;

TipoAluno *aloca();
void alterar(TipoAluno *paluno);
void opcoes(TipoAluno *paluno);

void main()
{
    TipoAluno *p;
    p = aloca();
    alterar(p);
    printf("\nAluno %s inserido!", p->nome);
    opcoes(p);
}

TipoAluno *aloca()
{
    TipoAluno *pa;
    pa = (TipoAluno *)malloc(sizeof(TipoAluno));
    if (!pa)
        return NULL;
    return pa;
}

void alterar(TipoAluno *paluno)
{
    printf("\nInforme nome:");
    fgets(paluno->nome, 50, stdin);
    printf("\nInforme RA:");
    scanf("%d", &(paluno->ra));
    printf("\nInforme idade:");
    scanf("%d", &(paluno->idade));
}

void opcoes(TipoAluno *paluno)
{
    int op;
    while (op)
    {
        printf("\nSelecione uma opcao: ");
        printf("\n0 - Encerrar.");
        printf("\n1 - Ver nome.");
        printf("\n2 - Ver idade.");
        printf("\n3 - Ver RA.");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\n%s", paluno->nome);
            break;
        case 2:
            printf("\n%d", paluno->idade);
            break;
        case 3:
            printf("\n%d", paluno->ra);
            break;
        }
    }
}